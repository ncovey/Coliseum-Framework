// 3D vector

#pragma once

#include "types.h"

namespace CF
{

namespace AfterMath
{

//	needed for multiplication
extern class Matrix3x3;

struct vec3
{
	// data members
	real32 x, y, z;

	//////////////////////////////////////////////////////////////////////////
	//	constructor(s)/destructor

	//	default ctor
	vec3();
	//	copy ctor
	vec3(const vec3& v);
	//	initialize vector with values
	vec3(real32 X, real32 Y, real32 Z);
	//	use a c-style array to create the vector
	vec3(const real32 (&v)[3]);
	// dtor
	~vec3();

	//////////////////////////////////////////////////////////////////////////
	//		operator overloads

	//	assignment operator
	vec3& operator=(const vec3& v);

	//////////////////////////////////////////////////////////////////////////
	//	arithmetic operators

	// cross product
	vec3& operator%=(const vec3&);
	//	vector * matrix multiplication
	vec3& operator*=(const Matrix3x3&);
	//	scalar mult
	vec3& operator*=(real32);
	//	scalar divide
	vec3& operator/=(real32);
	//	add
	vec3& operator+=(const vec3&);
	//	subtract
	vec3& operator-=(const vec3&);
	
	//////////////////////////////////////////////////////////////////////////
	//	manipulators

	//	returns the length of the vector without taking the square root of it
	real32 getLengthSquared() const;
	//	returns the length of the vector
	real32 getLength() const;
	//	normalizes the vector to a length of 1.0f
	vec3& normalize();
	//	returns a vector with a length of 1.0f
	vec3 getNormalized() const;
};	

//////////////////////////////////////////////////////////////////////////
//	inlines

//	comparison
inline bool operator==(const vec3& lhs, const vec3& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

//	cross product
inline vec3 operator%(vec3 lhs, const vec3& rhs) { return lhs %= rhs; }

//	dot product
inline real32 operator*(const vec3& lhs, const vec3& rhs)
{
	return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

//	scalar product
inline vec3 operator*(vec3 lhs, real32 rhs) { return lhs *= rhs; }
inline vec3 operator*(real32 rhs, vec3 lhs) { return lhs *= rhs; }
inline vec3 operator/(vec3 lhs, real32 rhs) { return lhs /= rhs; }

//	add/subtract
inline vec3 operator+(vec3 lhs, const vec3& rhs) { return lhs += rhs; }
inline vec3 operator-(vec3 lhs, const vec3& rhs) { return lhs -= rhs; }

//	vector * matrix multiplication
inline vec3 operator*(vec3 lhs, const Matrix3x3& rhs) { return lhs *= rhs; }

}

}