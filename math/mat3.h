//////////////////////////////////////////////////////////////////////////
//	mat3.h
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "primitives.h"

namespace CF
{
namespace AfterMath
{
	//////////////////////////////////////////////////////////////////////////
	//	Matrix 3x3 for 3D math
	class mat3
	{
	public:

		//////////////////////////////////////////////////////////////////////////
		//		ctor/dtor
		mat3();
		mat3(const mat3&);
		~mat3();

		//////////////////////////////////////////////////////////////////////////
		//		operator overloads

		// assignment operator
		mat3& operator=(const mat3&);

		// access operator
		const real32* operator[](uint32 idx) const;
		real32* operator[](uint32 idx);

		// addition
		mat3& operator+=(const mat3&);
		// subtraction
		mat3& operator-=(const mat3&);
		// multiplication
		mat3& operator*=(const mat3&);
		// scalar multiplication
		mat3& operator*=(real32 s);

		//////////////////////////////////////////////////////////////////////////
		//		manipulators

		// getters
		real32 getDiscriminant() const;

		mat3& invert();
		mat3 getInverse() const;
		
		mat3& transpose();
		mat3 getTranspose() const;
		
	private:
		real32 m_matrix[3][3];
	};

	//////////////////////////////////////////////////////////////////////////
	//	inlines

	// comparison
	extern inline bool operator==(const mat3& lhs, const mat3& rhs);

	// matrix multiplication
	extern inline mat3 operator*(mat3 lhs, const mat3& rhs);
	// addition
	extern inline mat3 operator+(mat3 lhs, const mat3& rhs);
	// subtraction
}
}
