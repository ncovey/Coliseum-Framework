// main.cpp

// defines the main entry point for the main application

// helps me detect memory leaks in the application
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include "fastmath.h"
#include "vec3.h"
#include "mat3.h"
#include "vect.h"
//#include "vector.h"
#include "list_d.h"

//#include "vector.h"

#include <Windows.h>
#include <stdio.h>
#include <iostream>

#include <xmmintrin.h>

//#pragma comment (linker, "/ENTRY:WinMainCRTStartup")
//#pragma comment (linker, "/SUBSYSTEM:WINDOWS")

using namespace CF;
using namespace AfterMath;


int main()
{
	{
		const real64 testVal = 43.0f;

		////return *pOut;
		printf("%f\n", frsqrt(testVal));

		////EGG::vector<uint32> v = EGG::vector<uint32>();
		//printf("%f\n", fsqrt(testVal));

		//EGG::vector<uint32> vInts = EGG::vector<uint32>();
		//EGG::vector<uint32>::iter itr;

	}

//	system("pause");
//	_CrtDumpMemoryLeaks();
//	return 0;
//}
//
//int main()
//{
	{
		std::cout << "sizeof(list_d) = " << sizeof(EGG::list_d<uint32>) << std::endl;

		EGG::list_d<int> l_ints = EGG::list_d<int>();
		EGG::list_d<vec3> l_vecs = EGG::list_d<vec3>();

		std::cout << "sizeof(mat3) = " << sizeof(mat3) << std::endl;

		float matrix3[3][3] = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };

		mat3 mtx = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };

		mtx = mat3({ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });
		mat3 mtx2 = { { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };

		mtx2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		mtx = mat3({ 0, 0, 0 }, { 1, 1, 1 }, { 2, 2, 2 });
		mtx = { { 0, 0, 0 }, { 1, 1, 1 }, { 2, 2, 2 } };

		mtx *= mtx2;

		mtx + mtx2;
		mtx - mtx2;
		mtx * mtx2;

		vec3 v = { 1, 1, 1 };
		vec3 v3 = { 2, 4, 6 };
		v = { 0, 0, 0 };

		vec3 v2 = v * mtx2;
		v2 = v + v3;

		vec3 v4 = v2 * mtx2;

		//EGG::vect<uint32> vint = 
	}


	int32 a(3), b(-7);
	std::cout << "3^(-7) = " << fpow(3, -7) << std::endl;
	std::cout << "1.28347 ^ 25.323489 = " << fpow(1.28347 , 25.323489) << std::endl;
	std::cout << "155 ^ -1/2 = " << frsqrt(155) << std::endl;
	std::cout << "sqrt 144 = " << fsqrt(144) << std::endl;
	std::cout << "ln (345454656565) = " << fln(345454656565) << std::endl;
	std::cout << "size of vec3 : " << sizeof(vec3) << std::endl;
	printf("3^7=%d\n", pow(3, 7));

	{
		//CF::Egg::vect<CF::uint32> vec = CF::Egg::vect<CF::uint32>();
		CF::EGG::vect<AfterMath::vec3*> vec = CF::EGG::vect<AfterMath::vec3*>();
		for (uint32 i = 0; i < 128; i++)
		{
			vec.pushfront(new AfterMath::vec3(i, i + 1, i + 2));
		}

		CF::EGG::vect<AfterMath::vec3*> vec2 = vec;

		// deep copy
		for (uint32 i = 0; i < vec.size(); i++)
			vec2[i] = new vec3(*vec[i]);

		for (uint32 i = 0; i < vec2.size(); i++)
		{
			std::cout << "vec2[" << i << "] = {"
				<< vec2[i]->x << ","
				<< vec2[i]->y << ","
				<< vec2[i]->z << "}" << std::endl;
		}

		for (uint32 i = 0; i < vec.size(); i++)
			vec[i]->normalize();

		//vec2 = vec;

		for (uint32 i = 0; i < vec2.size(); i++)
		{
			std::cout << "vec2[" << i << "] = {"
				<< vec2[i]->x << ","
				<< vec2[i]->y << ","
				<< vec2[i]->z << "}" << std::endl;
		}

		vec.condense();
		vec2.condense();

		auto vec3 = vec + vec2;
		uint32 i(0);
		while (vec3.size() > 0)
		{
			vec3.removefront();
			vec3.condense();
			vec3[0]->normalize();
			std::cout << "vec3[" << i++ << "] = {"
				<< vec3[0]->x << ","
				<< vec3[0]->y << ","
				<< vec3[0]->z << "}" << std::endl;
		}

		// clean up
		for (uint32 i = 0; i < vec.size(); i++)
			delete vec[i];

		for (uint32 i = 0; i < vec2.size(); i++)
			delete vec2[i];

		for (uint32 i = 0; i < vec3.size(); i++)
			delete vec3[i];

	}

	{
		//CF::Egg::vect<CF::uint32> vec = CF::Egg::vect<CF::uint32>();
		CF::EGG::vect<AfterMath::vec3> vec = CF::EGG::vect<AfterMath::vec3>();
		for (uint32 i = 0; i < 45; i++)
		{
			vec.pushfront(AfterMath::vec3(i, i + 1, i + 2));
		}

		CF::EGG::vect<AfterMath::vec3> vec2 = vec;
		vec.condense();
		vec2.condense();

		for (uint32 i = 0; i < vec.size(); i++)
			vec[i].normalize();

		for (uint32 i = 0; i < vec2.size(); i++)
		{
			std::cout << "vec2[" << i << "] = {"
				<< vec2[i].x << ","
				<< vec2[i].y << ","
				<< vec2[i].z << "}" << std::endl;
		}

		for (uint32 i = 0; i < vec.size(); i++)
		{
			std::cout << "vec[" << i << "] = {"
				<< vec[i].x << ","
				<< vec[i].y << ","
				<< vec[i].z << "}" << std::endl;
		}
	}

	{
		CF::EGG::vect<AfterMath::vec3> vec = CF::EGG::vect<AfterMath::vec3>();
		for (uint32 i = 0; i < 5; i++)
		{
			vec.pushback(AfterMath::vec3(i, i + 1, i + 2));
		}

		for (uint32 i = 0; i < 5; i++)
		{
			vec.insertafter(3, AfterMath::vec3(-1,-1,-1));
		}

		vec.removeback();

		for (uint32 i = 0; i < vec.size(); i++)
		{
			std::cout << "vec[" << i << "] = {"
				<< vec[i].x << ","
				<< vec[i].y << ","
				<< vec[i].z << "}" << std::endl;
		}

		auto little_vec = CF::EGG::vect<AfterMath::vec3>();

		for (uint32 i = 0; i < 5; i++)
		{
			little_vec.pushback(AfterMath::vec3(i,i,i));
		}

		auto vec2 = vec + little_vec;

		//for (uint32 i = 0; i < vec2.size(); i++)
		uint32 i(0), midpt(0);
		while (vec2.size() > 0)
		{
			midpt = vec2.size() / 2;
			std::cout << "vec2[" << midpt << "] = {"
				<< vec2[midpt].x << ","
				<< vec2[midpt].y << ","
				<< vec2[midpt].z << "}" << std::endl;
			vec2.remove(midpt);
			i++;
		}
		int x = 0;
	}

	system("pause");
	_CrtDumpMemoryLeaks();
	return 0;
}