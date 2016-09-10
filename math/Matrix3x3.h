//////////////////////////////////////////////////////////////////////////
//	mat3.h
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "types.h"

namespace CF
{
namespace AfterMath
{
	//////////////////////////////////////////////////////////////////////////
	//	Matrix 3x3 for 3D math
	class Matrix3x3
	{
	private:
		//////////////////////////////////////////////////////////////////////////
		//	hidden aggregate data structures to use aggregate initialization
		struct __matrix1x9
		{
			real64 _00, _01, _02, _10, _11, _12, _20, _21, _22;
		};
		//struct __matrix1x3
		//{
		//	real64 _0, _1, _2;
		//};
		//struct __matrix3x3
		//{
		//	real64 _0[3], _1[3], _2[3];
		//};

	public:

		//////////////////////////////////////////////////////////////////////////
		//		ctor/dtor
		Matrix3x3();
		Matrix3x3(const Matrix3x3&);
		Matrix3x3(const real64 (&m)[3][3]);
		Matrix3x3(const real64 (&row1)[3], const real64 (&row2)[3], const real64 (&row3)[3]);
		//mat3(const real64 (&a)[9]);
		//mat3(const __matrix1x9&);
		//mat3(const __matrix1x3&, const __matrix1x3&, const __matrix1x3&);
		//mat3(const __matrix3x3&);
		~Matrix3x3();

		//////////////////////////////////////////////////////////////////////////
		//		operator overloads

		// assignment operator
		//mat3& operator=(const real64 (&m)[3][3]);
		Matrix3x3& operator=(const Matrix3x3&);
		Matrix3x3& operator=(const __matrix1x9&);
		//mat3& operator=(const __matrix3x3&);

		// row access operator
		const real64* operator[](uint32 row) const;
		real64* operator[](uint32 row);

		// single cell access operator
		const real64& operator()(uint32 row, uint32 col) const;
		real64& operator()(uint32 row, uint32 col);

		//////////////////////////////////////////////////////////////////////////
		//	Arithmetic operators

		// addition
		Matrix3x3& operator+=(const Matrix3x3&);
		// subtraction
		Matrix3x3& operator-=(const Matrix3x3&);
		// multiplication
		Matrix3x3& operator*=(const Matrix3x3&);
		// scalar multiplication
		Matrix3x3& operator*=(real64 s);
		// scalar division
		Matrix3x3& operator/=(real64 s);

		//////////////////////////////////////////////////////////////////////////
		//		manipulators

		// determinant
		real64 getdeterminant() const;

		// invert contents of matrix
		Matrix3x3& invert();
		// get what the matrix would be if inverted
		Matrix3x3 getinverse() const;
		
		// transpose contents of matrix
		Matrix3x3& transpose();
		// get what matrix would be if transposed
		Matrix3x3 gettranspose() const;
		
	private:

		// 3 x 3 matrix
		real64 m_matrix[3][3];
	};

	//////////////////////////////////////////////////////////////////////////
	//					inlines

	// matrix comparison
	inline bool operator==(const Matrix3x3& lhs, const Matrix3x3& rhs)
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
	inline Matrix3x3 operator*(Matrix3x3 lhs, const Matrix3x3& rhs)
	{
		return lhs *= rhs;
	}

	//	matrix addition
	inline Matrix3x3 operator+(Matrix3x3 lhs, const Matrix3x3& rhs)
	{
		return lhs += rhs;
	}

	//	matrix subtraction
	inline Matrix3x3 operator-(Matrix3x3 lhs, const Matrix3x3& rhs)
	{
		return lhs -= rhs;
	}

}
}
