// 3D vector

#include "vec3.h"
#include "mat3.h"
#include "fastmath.h"

using namespace CF;
using namespace AfterMath;

//////////////////////////////////////////////////////////////////////////
// ctors

//	initializes vector with default values of 0
vec3::vec3() 
	: x(0.0f), y(0.0f), z(0.0f) 
{

}

// copy ctor
vec3::vec3(const vec3& v) 
	: x(v.x), y(v.y), z(v.z) 
{

}

//	initialize vector with values
vec3::vec3(real32 X, real32 Y, real32 Z) 
	: x(X), y(Y), z(Z) 
{

}

//	initialize with c-style array
vec3::vec3(const real32(&v)[3])
	: x(v[0]), y(v[1]), z(v[2])
{
	
}

//////////////////////////////////////////////////////////////////////////
// dtor
vec3::~vec3() {}

//////////////////////////////////////////////////////////////////////////
//	Assignment operator
//	
vec3& vec3::operator=(const vec3& v)
{
	x = v.x; y = v.y; z = v.z;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// cross product
vec3& vec3::operator%=(const vec3& v)
{
	// (yz - zy, xz - zx, xy - yx)
	x = (y*v.z - y*v.z); y = (x*v.z - z*v.x); z = (x*v.y - y*v.x);
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// scalar mult
vec3& vec3::operator*=(real32 s)
{
	x *= s; y *= s; z *= s;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
//	vector * matrix multiplication
vec3& vec3::operator*=(const mat3& m)
{
	x *= (m[0][0] + m[1][0] + m[2][0]);
	y *= (m[0][1] + m[1][1] + m[2][1]);
	z *= (m[0][2] + m[1][2] + m[2][2]);

	return *this;
}

//////////////////////////////////////////////////////////////////////////
// scalar divide
vec3& vec3::operator/=(real32 s)
{
	x /= s; y /= s; z /= s;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// add
vec3& vec3::operator+=(const vec3& v)
{
	x += v.x; y += v.y; z += v.z;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// subtract
vec3& vec3::operator-=(const vec3& v)
{
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// manipulators

//////////////////////////////////////////////////////////////////////////
// if obtaining square root is not necessary
real32 vec3::getLengthSquared() const
{
	return x*x + y*y + z*z;
}

//////////////////////////////////////////////////////////////////////////
// actual length
real32 vec3::getLength() const
{
	return fsqrt(x*x + y*y + z*z);
}

//////////////////////////////////////////////////////////////////////////
// normalize vector to length of 1
vec3& vec3::normalize()
{
	*this /= getLength();
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// obtain the value of a vector if it was normalized
vec3 vec3::getNormalized() const
{
	vec3 v(*this);
	return v.normalize();
}