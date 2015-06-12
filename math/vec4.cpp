//////////////////////////////////////////////////////////////////////////
//	vec4.cpp
//	
//	4D vector
//	Implementation
//////////////////////////////////////////////////////////////////////////

#include "vec4.h"

using namespace CF;
using namespace AfterMath;

//////////////////////////////////////////////////////////////////////////
//					Constructors


//	default ctor
vec4::vec4()
	: x(0), y(0), z(0), w(0)
{

}

//	copy ctor
vec4::vec4(const vec4& v)
	: x(v.x), y(v.y), z(v.z), w(v.w)
{

}

//	init with values
vec4::vec4(real32 X, real32 Y, real32 Z, real32 W)
	: x(X), y(Y), z(Z), w(W)
{

}

//	aggregate list (VC++12 or later) / c-style array
vec4::vec4(const real32(&v)[4])
	: x(v[0]), y(v[1]), z(v[2]), w(v[3])
{

}

//////////////////////////////////////////////////////////////////////////
//	destructor
vec4::~vec4()
{

}

//////////////////////////////////////////////////////////////////////////
//					Operator Overloads

//	assignment operator
vec4& vec4::operator=(const vec4& v)
{
	x = v.x; y = v.y; z = v.z; w = z.w;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
//		Arithmetic Operators

//	cross product
//	this doesn't actually make sense: you would need three 4D vectors in order to do this
//	doing this will be evaluated as if this were the cross product of 
//	<   x,   y,   z,   w >
//	< v.x, v.y, v.z, v.w >
//	<   1,   1,   1,   0 >
//	< [X], [Y],	[Z], [W] >
vec4& vec4::operator%=(const vec4& v)
{
	real32 X = y*v.z - z*v.y;
	real32 Y = z*v.x - x*v.z;
	real32 Z = x*v.y - y*v.x;
	real32 W = w*v.w;

	x = X; y = Y; z = Z; w = W;
}
