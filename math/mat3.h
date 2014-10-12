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
	private:
		//////////////////////////////////////////////////////////////////////////
		//	hidden aggregate data structures to use aggregate initialization
		struct __matrix1x9
		{
			real32 _00, _01, _02, _10, _11, _12, _20, _21, _22;
		};
		//struct __matrix1x3
		//{
		//	real32 _0, _1, _2;
		//};
		//struct __matrix3x3
		//{
		//	real32 _0[3], _1[3], _2[3];
		//};

	public:

		//////////////////////////////////////////////////////////////////////////
		//		ctor/dtor
		mat3();
		mat3(const mat3&);
		mat3(const real32 (&m)[3][3]);
		mat3(const real32 (&row1)[3], const real32 (&row2)[3], const real32 (&row3)[3]);
		//mat3(const real32 (&a)[9]);
		//mat3(const __matrix1x9&);
		//mat3(const __matrix1x3&, const __matrix1x3&, const __matrix1x3&);
		//mat3(const __matrix3x3&);
		~mat3();

		//////////////////////////////////////////////////////////////////////////
		//		operator overloads

		// assignment operator
		//mat3& operator=(const real32 (&m)[3][3]);
		mat3& operator=(const mat3&);
		mat3& operator=(const __matrix1x9&);
		//mat3& operator=(const __matrix3x3&);

		// row access operator
		const real32* operator[](uint32 row) const;
		real32* operator[](uint32 row);

		// single cell access operator
		const real32& operator()(uint32 row, uint32 col) const;
		real32& operator()(uint32 row, uint32 col);

		//////////////////////////////////////////////////////////////////////////
		//	Arithmetic operators

		// addition
		mat3& operator+=(const mat3&);
		// subtraction
		mat3& operator-=(const mat3&);
		// multiplication
		mat3& operator*=(const mat3&);
		// scalar multiplication
		mat3& operator*=(real32 s);
		// scalar division
		mat3& operator/=(real32 s);

		//////////////////////////////////////////////////////////////////////////
		//		manipulators

		// determinant
		real32 getdeterminant() const;

		// invert contents of matrix
		mat3& invert();
		// get what the matrix would be if inverted
		mat3 getinverse() const;
		
		// transpose contents of matrix
		mat3& transpose();
		// get what matrix would be if transposed
		mat3 gettranspose() const;
		
	private:

		// 3 x 3 matrix
		real32 m_matrix[3][3];
	};

	//////////////////////////////////////////////////////////////////////////
	//					inlines

	// matrix comparison
	inline bool operator==(const mat3& lhs, const mat3& rhs)
	{
		for (uint32 i = 0; i < 3; i++)
		{
			for (uint32 j = 0; j < 3; j++)
			{
				if (lhs[i][j] != rhs[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}

	//	matrix multiplication
	inline mat3 operator*(mat3 lhs, const mat3& rhs)
	{
		return lhs *= rhs;
	}

	//	matrix addition
	inline mat3 operator+(mat3 lhs, const mat3& rhs)
	{
		return lhs += rhs;
	}

	//	matrix subtraction
	inline mat3 operator-(mat3 lhs, const mat3& rhs)
	{
		return lhs -= rhs;
	}

}
}
