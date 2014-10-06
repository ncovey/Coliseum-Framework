// 3D vector

#include "vec3.h"
#include "fastmath.h"

using namespace CF;
using namespace AfterMath;

//////////////////////////////////////////////////////////////////////////
// ctors
vec3::vec3() : x(0.0f), y(0.0f), z(0.0f) {}
vec3::vec3(CF::real32 X, CF::real32 Y, CF::real32 Z) : x(X), y(Y), z(Z) {}

// copy ctor
vec3::vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {}

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
vec3& vec3::operator*=(CF::real32 s)
{
	x *= s; y *= s; z *= s;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// scalar divide
vec3& vec3::operator/=(CF::real32 s)
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
CF::real32 vec3::getLengthSquared() const
{
	return x*x + y*y + z*z;
}

//////////////////////////////////////////////////////////////////////////
// actual length
CF::real32 vec3::getLength() const
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

// *************** End vec3 class definitions ***************

// inlines

inline bool operator==(const vec3& lhs, const vec3& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

inline vec3& operator%(vec3 lhs, const vec3& rhs)
{
	return lhs%=rhs;
}

// dot product
inline CF::real32 operator*(const vec3& lhs, const vec3& rhs)
{
	return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

// scalar product
inline vec3& operator*(vec3 lhs, CF::real32 rhs) { return lhs *= rhs; }
inline vec3& operator*(CF::real32 rhs, vec3 lhs) { return lhs *= rhs; }
inline vec3& operator/(vec3 lhs, CF::real32 rhs) { return lhs /= rhs; }

// add/subtract
inline vec3& operator+(vec3 lhs, const vec3& rhs) { return lhs += rhs; }
inline vec3& operator-(vec3 lhs, const vec3& rhs) { return lhs -= rhs; }