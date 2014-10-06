// 3D vector

#pragma once

#include "primitives.h"

namespace CF
{

namespace AfterMath
{

struct vec3
{
	// data members
	CF::real32 x, y, z;

	// ctors
	vec3();
	vec3(CF::real32 X, CF::real32 Y, CF::real32 Z);
	vec3(const vec3& v);
	// dtor
	~vec3();

	// assignment operator
	vec3& operator=(const vec3& v);
	// cross product
	vec3& operator%=(const vec3& v);
	// scalar mult
	vec3& operator*=(CF::real32 s);
	// scalar divide
	vec3& operator/=(CF::real32 s);
	// add
	vec3& operator+=(const vec3& v);
	// subtract
	vec3& operator-=(const vec3& v);

	// manipulators
	CF::real32 getLengthSquared() const;
	CF::real32 getLength() const;
	vec3& normalize();
	vec3 getNormalized() const;
};	

//////////////////////////////////////////////////////////////////////////
//	inlines

// not sure if I need the 'extern' keyword...

// comparison
extern inline bool operator==(const vec3& lhs, const vec3& rhs);

// cross product
extern inline vec3& operator%(vec3 lhs, const vec3& rhs);

// dot product
extern inline CF::real32 operator*(vec3 lhs, const vec3& rhs);

// scalar product
extern inline vec3& operator*(vec3 lhs, float rhs);
extern inline vec3& operator*(CF::real32 rhs, vec3 lhs);
extern inline vec3& operator/(vec3 lhs, float rhs);

// add/subtract
extern inline vec3& operator+(vec3 lhs, const vec3& rhs);
extern inline vec3& operator-(vec3 lhs, const vec3& rhs);

}

}