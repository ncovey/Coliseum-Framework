//////////////////////////////////////////////////////////////////////////
// follows this DirectX 11 tutorial:
// http://www.directxtutorial.com/Lesson.aspx?lessonid=11-4-1
// so a lot of code was copied since I was doing the lessons
//////////////////////////////////////////////////////////////////////////

// windows application headers
#include <Windows.h>
#include <windowsx.h>

// DirectX and Direct3D
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>

// include the Direct3D libs
//#ifdef _DEBUG
//#pragma comment (lib, "d3d11.lib")
//#pragma comment (lib, "d3dx11d.lib")
//#pragma comment (lib, "d3dx10d.lib")
//#else
//#pragma comment (lib, "d3d11.lib")
//#pragma comment (lib, "d3dx11.lib")
//#pragma comment (lib, "d3dx10.lib")
//#endif // DEBUG

#pragma comment (linker, "/ENTRY:WinMainCRTStartup")
#pragma comment (linker, "/SUBSYSTEM:WINDOWS")

//////////////////////////////////////////////////////////////////////////
//	structs

struct VERTEX
{
	FLOAT X, Y, Z;		// position
	D3DXCOLOR Color;	// color
};

//////////////////////////////////////////////////////////////////////////
//	Variables

// define the screen resolution
const unsigned SCREEN_WIDTH = 1280;
const unsigned SCREEN_HEIGHT = 720;

// globals
IDXGISwapChain *swapchain;		// pointer to the swap chain interface
ID3D11Device *dev;				// pointer to Direct3D device interface
ID3D11DeviceContext *devcon;	// pointer to Direct3D device context

ID3D11RenderTargetView *backbuffer;
ID3D11InputLayout *pLayout;

ID3D11VertexShader *pVS;		// the vertex shader
ID3D11PixelShader *pPS;			// the pixel shader
ID3D11Buffer *pVBuffer;			// pointer to vertex buffer

//////////////////////////////////////////////////////////////////////////
//	function prototypes

// Direct3D
void InitD3D(HWND hWnd);	// sets up and init D3D
void InitPipeline(void);	// sets up the D3D rendering pipeline
void InitGraphics(void);	// sets up some graphics for rendering
void CleanD3D(void);		// close D3D and release memory

// Render
void RenderFrame(void); // single frame render

// WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


//////////////////////////////////////////////////////////////////////////
//	WinMain
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	// create message box:
	//MessageBox(NULL,
	//	"Hello World!",
	//	"Just another Hello World program!",
	//	MB_ICONEXCLAMATION | MB_OK);

	//////////////////////////////////////////////////////////////////////////
	/*
		1. Register the window class:	RegisterClassEx();
		2. Create the window:			CreateWindowEx();
		3. Show the window:				ShowWindow();
	*/

	// the handle for the window, filled by a function
	HWND hWnd;
	// this struct holds information for the window class
	WNDCLASSEX wc;
	
	// clear out the window class for use
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	// fill in the struct with the needed information
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.hbrBackground = (HBRUSH)COLOR_WINDOW; // not sure why a cast is done here or what type of cast
	wc.lpszClassName = "WindowClass1";

	// register the window class
	RegisterClassEx(&wc);

	// adjust size of the actual window (has borders) so the client window inside is
	// of the desired dimensions
	RECT wr = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }; // set the size, but not the position
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE); // adjust the size

	// create the window and use the result as the handle
	hWnd = CreateWindowEx(
		NULL,
		"WindowClass1", // name of the window class
		"Our First Windowed Program", // title of window
		WS_OVERLAPPEDWINDOW, // window style
		100, 100, // x-y position
		wr.right-wr.left,	// width of window
		wr.bottom - wr.top, // height of window
		NULL, // parent window
		NULL, // menus
		hInstance, // application handle
		NULL); // used with multiple windows

	// display the window on the screen
	ShowWindow(hWnd, nCmdShow);

	// setup and init D3D:
	InitD3D(hWnd);

	//////////////////////////////////////////////////////////////////////////
	// enter the main loop:

	// this struct holds Windows event messages:
	MSG msg;

	// wait for the next message in the queue, store the result in 'msg'
	// HWND = NULL means to get the next message for any of our windows. 
	// We could put hWnd here and it wouldn't make any difference; 
	// but it would if we had multiple windows.
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// translate keystroke messages into the right format
			TranslateMessage(&msg);

			// send the message to the WindowProc function
			DispatchMessage(&msg);

			// check to see if it is time to quit
			if (msg.message == WM_QUIT)
				break;
		}
		else
		{
			RenderFrame();

			// Run game code here
			// ...
			// ...
		}
	}

	// clean up DirectX and COM:
	CleanD3D();

	// return this part of the WM_QUIT message to Windows:
	return msg.wParam;
}

// impl main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// sort through and find what code to run for the message given
	switch (message)
	{
	// this message is read when the window is closed
	case WM_DESTROY:
	{
		// close application entirely
		PostQuitMessage(0);
		return 0;
	} 
		break;
	default:
		break;
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}

// init and prep D3D for use:
void InitD3D(HWND hWnd)
{
	//////////////////////////////////////////////////////////////////////////
	//	Direct3D initialization

	// create a struct to hold info about swap chain
	DXGI_SWAP_CHAIN_DESC scd;

	// clear struct for use
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

	// fill in the struct
	scd.BufferCount = 1;								// back buffers
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // 32-bit color
	scd.BufferDesc.Width = SCREEN_WIDTH;				// set back buffer width
	scd.BufferDesc.Height = SCREEN_HEIGHT;				// set back buffer height
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;	// swap chain usage
	scd.OutputWindow = hWnd;							// use our window!
	scd.SampleDesc.Count = 4;							// how many multisamples (for MSAA :D)
	scd.Windowed = TRUE;								// windowed/fullscreen mode
	scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; // allow fullscreen switching

	// create a device, device context, and swap chain using the info from struct 'scd':
	D3D11CreateDeviceAndSwapChain(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		NULL,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&scd,
		&swapchain,
		&dev,
		NULL,
		&devcon);

	//////////////////////////////////////////////////////////////////////////
	//	set the render target

	// get the address of the back buffer
	ID3D11Texture2D *pBackBuffer;
	swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	
	// user the back buffer address to create the render target
	dev->CreateRenderTargetView(pBackBuffer, NULL, &backbuffer);
	pBackBuffer->Release(); // doesn't destroy back buffer, only closes the texture object

	// set the render target as the back buffer
	devcon->OMSetRenderTargets(1, &backbuffer, NULL);

	//////////////////////////////////////////////////////////////////////////
	//	set the viewport
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = SCREEN_WIDTH;
	viewport.Height = SCREEN_HEIGHT;

	devcon->RSSetViewports(1, &viewport);

	InitPipeline();
	InitGraphics();

}

// set up the D3D rendering pipeline
void InitPipeline()
{
	// load and compile the two shaders
	ID3D10Blob *VS, *PS; // vertex, pixel shader
	D3DX11CompileFromFile("shaders.shader", 0, 0, "VShader", "vs_4_0", 0, 0, 0, &VS, 0, 0);
	D3DX11CompileFromFile("shaders.shader", 0, 0, "PShader", "ps_4_0", 0, 0, 0, &PS, 0, 0);
	
	// encapsulate both shaders into shader objects
	dev->CreateVertexShader(VS->GetBufferPointer(), VS->GetBufferSize(), NULL, &pVS);
	dev->CreatePixelShader(PS->GetBufferPointer(), PS->GetBufferSize(), NULL, &pPS);

	// set the shader objects
	devcon->VSSetShader(pVS, 0, 0);
	devcon->PSSetShader(pPS, 0, 0);

	// create the input layout object
	// this tells the GPU how our VERTEX data is formatted so it can read and process it
	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};

	dev->CreateInputLayout(ied, 2, VS->GetBufferPointer(), VS->GetBufferSize(), &pLayout);
	devcon->IASetInputLayout(pLayout);
}

// sets up some graphics for rendering
void InitGraphics()
{
	// create a triangle using the VERTEX struct
	VERTEX OurVertices[] =
	{
		{ 0.0f, 0.5f, 0.0f, D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f) },
		{ 0.45f, -0.5, 0.0f, D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f) },
		{ -0.45f, -0.5f, 0.0f, D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f) }
	};

	// create the vertex buffer
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));

	bd.Usage = D3D11_USAGE_DYNAMIC;				// write access access by CPU and GPU
	bd.ByteWidth = sizeof(VERTEX) * 3;			// size is VERTEX * 3 (for triangle)
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// use as a vertex buffer
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE; // allow CPU to write into buffer

	dev->CreateBuffer(&bd, NULL, &pVBuffer);	// create the buffer via description struct

	// copy vertices into the buffer:
	D3D11_MAPPED_SUBRESOURCE ms;
	devcon->Map(pVBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &ms);	// map the buffer
	memcpy(ms.pData, OurVertices, sizeof(OurVertices));
	devcon->Unmap(pVBuffer, NULL);

}

// used to render single frame
void RenderFrame()
{
	// clear the back buffer to a deep blue
	devcon->ClearRenderTargetView(backbuffer, D3DXCOLOR(0.0f, 0.2f, 0.4f, 1.0f));

	// select which vertex buffer to display
	static UINT stride = sizeof(VERTEX);
	static UINT offset = 0;
	devcon->IASetVertexBuffers(0, 1, &pVBuffer, &stride, &offset);

	// select which primitive type we are using
	devcon->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// draw the vertex buffer to the back buffer
	devcon->Draw(3, 0);

	// switch the back buffer and the front buffer
	swapchain->Present(0, 0);

}

// clean up D3D and COM
void CleanD3D()
{
	// D3D cannot close while in fullscreen?
	swapchain->SetFullscreenState(FALSE, NULL); // switches to windowed mode

	// close and release all existing COM objects
	swapchain->Release();
	dev->Release();
	devcon->Release();
	backbuffer->Release();
	pVBuffer->Release();
	pVS->Release();
	pPS->Release();
	pLayout->Release();
}