//////////////////////////////////////////////////////////////////////////
//	mat3.cpp
//////////////////////////////////////////////////////////////////////////

#include "Matrix3x3.h"

using namespace CF;
using namespace AfterMath;

//////////////////////////////////////////////////////////////////////////
//	default ctor
Matrix3x3::Matrix3x3()
{
	m_matrix[0][0] =
		m_matrix[0][1] =
		m_matrix[0][2] =
		m_matrix[1][0] =
		m_matrix[1][1] =
		m_matrix[1][2] =
		m_matrix[2][0] =
		m_matrix[2][1] =
		m_matrix[2][2] = 0;
}

//////////////////////////////////////////////////////////////////////////
//	copy ctor
Matrix3x3::Matrix3x3(const mat3& m)
{
	*this = m;
}

//////////////////////////////////////////////////////////////////////////
//
Matrix3x3::Matrix3x3(const real64 (&row1)[3], const real64 (&row2)[3], const real64 (&row3)[3])
{
	m_matrix[0][0] = row1[0];
	m_matrix[0][1] = row1[1];
	m_matrix[0][2] = row1[2];
	m_matrix[1][0] = row2[0];
	m_matrix[1][1] = row2[1];
	m_matrix[1][2] = row2[2];
	m_matrix[2][0] = row3[0];
	m_matrix[2][1] = row3[1];
	m_matrix[2][2] = row3[2];
}

//////////////////////////////////////////////////////////////////////////
//	
//mat3::mat3(const real64 (&a)[9])
//{
//	m_matrix[0][0] = a[0];
//	m_matrix[0][1] = a[1];
//	m_matrix[0][2] = a[2];
//	m_matrix[1][0] = a[3];
//	m_matrix[1][1] = a[4];
//	m_matrix[1][2] = a[5];
//	m_matrix[2][0] = a[6];
//	m_matrix[2][1] = a[7];
//	m_matrix[2][2] = a[8];
//}

//////////////////////////////////////////////////////////////////////////
//	
//mat3::mat3(const __matrix1x9& m)
//{
//	*this = m;
//}

//////////////////////////////////////////////////////////////////////////
//	
//mat3::mat3(const __matrix1x3& row1, const __matrix1x3& row2, const __matrix1x3& row3)
//{
//	m_matrix[0][0] = row1._0;
//	m_matrix[0][1] = row1._1;
//	m_matrix[0][2] = row1._2;
//	m_matrix[1][0] = row2._0;
//	m_matrix[1][1] = row2._1;
//	m_matrix[1][2] = row2._2;
//	m_matrix[2][0] = row3._0;
//	m_matrix[2][1] = row3._1;
//	m_matrix[2][2] = row3._2;
//}

//////////////////////////////////////////////////////////////////////////
//	
//mat3::mat3(const __matrix3x3& m)
//{
//	//*this = m;
//	m_matrix[0][0] = m._0[0];
//	m_matrix[0][1] = m._0[1];
//	m_matrix[0][2] = m._0[2];
//	m_matrix[1][0] = m._1[0];
//	m_matrix[1][1] = m._1[1];
//	m_matrix[1][2] = m._1[2];
//	m_matrix[2][0] = m._2[0];
//	m_matrix[2][1] = m._2[1];
//	m_matrix[2][2] = m._2[2];
//
//}

//////////////////////////////////////////////////////////////////////////
//	c-style matrix ctor
Matrix3x3::Matrix3x3(const real64 (&m)[3][3])
{
	//*this = m;
	m_matrix[0][0] = m[0][0];
	m_matrix[0][1] = m[0][1];
	m_matrix[0][2] = m[0][2];
	m_matrix[1][0] = m[1][0];
	m_matrix[1][1] = m[1][1];
	m_matrix[1][2] = m[1][2];
	m_matrix[2][0] = m[2][0];
	m_matrix[2][1] = m[2][1];
	m_matrix[2][2] = m[2][2];
}

//////////////////////////////////////////////////////////////////////////
//	dtor
Matrix3x3::~Matrix3x3()
{

}

//////////////////////////////////////////////////////////////////////////
//	assignment operator
//mat3& mat3::operator=(const real64 (&m)[3][3])
//{
//	m_matrix[0][0] = m[0][0];
//	m_matrix[0][1] = m[0][1];
//	m_matrix[0][2] = m[0][2];
//	m_matrix[1][0] = m[1][0];
//	m_matrix[1][1] = m[1][1];
//	m_matrix[1][2] = m[1][2];
//	m_matrix[2][0] = m[2][0];
//	m_matrix[2][1] = m[2][1];
//	m_matrix[2][2] = m[2][2];
//
//	return *this;
//}

//////////////////////////////////////////////////////////////////////////
//	
Matrix3x3& Matrix3x3::operator=(const mat3& m)
{
	//*this = m.m_matrix;
	m_matrix[0][0] = m[0][0];
	m_matrix[0][1] = m[0][1];
	m_matrix[0][2] = m[0][2];
	m_matrix[1][0] = m[1][0];
	m_matrix[1][1] = m[1][1];
	m_matrix[1][2] = m[1][2];
	m_matrix[2][0] = m[2][0];
	m_matrix[2][1] = m[2][1];
	m_matrix[2][2] = m[2][2];
	return *this;
}

//////////////////////////////////////////////////////////////////////////
//	
Matrix3x3& Matrix3x3::operator=(const __matrix1x9& m)
{
	m_matrix[0][0] = m._00;
	m_matrix[0][1] = m._01;
	m_matrix[0][2] = m._02;
	m_matrix[1][0] = m._10;
	m_matrix[1][1] = m._11;
	m_matrix[1][2] = m._12;
	m_matrix[2][0] = m._20;
	m_matrix[2][1] = m._21;
	m_matrix[2][2] = m._22;

	return *this;
}

//////////////////////////////////////////////////////////////////////////
//	
//mat3& mat3::operator=(const __matrix3x3& m)
//{
//	m_matrix[0][0] = m._0[0];
//	m_matrix[0][1] = m._0[1];
//	m_matrix[0][2] = m._0[2];
//	m_matrix[1][0] = m._1[0];
//	m_matrix[1][1] = m._1[1];
//	m_matrix[1][2] = m._1[2];
//	m_matrix[2][0] = m._2[0];
//	m_matrix[2][1] = m._2[1];
//	m_matrix[2][2] = m._2[2];
//
//	return *this;
//}

//////////////////////////////////////////////////////////////////////////
//	access operators
const real64* Matrix3x3::operator[](uint32 idx) const
{
	return m_matrix[idx];
}

real64* Matrix3x3::operator[](uint32 idx)
{	// call const version of operator
	return const_cast<real64*>(static_cast<const mat3&>(*this)[idx]);
}

const real64& Matrix3x3::operator()(uint32 row, uint32 col) const
{
	return m_matrix[row][col];
}

real64& Matrix3x3::operator()(uint32 row, uint32 col)
{	// call const version of operator
	return const_cast<real64&>(static_cast<const mat3&>(*this)(row, col));
}

//////////////////////////////////////////////////////////////////////////
//	Arithmetic Operators

//	addition
Matrix3x3& Matrix3x3::operator+=(const mat3& m)
{
	m_matrix[0][0] += m.m_matrix[0][0];
	m_matrix[0][1] += m.m_matrix[0][1];
	m_matrix[0][2] += m.m_matrix[0][2];
	m_matrix[1][0] += m.m_matrix[1][0];
	m_matrix[1][1] += m.m_matrix[1][1];
	m_matrix[1][2] += m.m_matrix[1][2];
	m_matrix[2][0] += m.m_matrix[2][0];
	m_matrix[2][1] += m.m_matrix[2][1];
	m_matrix[2][2] += m.m_matrix[2][2];

	return *this;
}

//	subtraction
Matrix3x3& Matrix3x3::operator-=(const mat3& m)
{
	m_matrix[0][0] -= m.m_matrix[0][0];
	m_matrix[0][1] -= m.m_matrix[0][1];
	m_matrix[0][2] -= m.m_matrix[0][2];
	m_matrix[1][0] -= m.m_matrix[1][0];
	m_matrix[1][1] -= m.m_matrix[1][1];
	m_matrix[1][2] -= m.m_matrix[1][2];
	m_matrix[2][0] -= m.m_matrix[2][0];
	m_matrix[2][1] -= m.m_matrix[2][1];
	m_matrix[2][2] -= m.m_matrix[2][2];

	return *this;
}

//	multiplication
Matrix3x3& Matrix3x3::operator*=(const mat3& m)
{
	return *this =
	{ 
	{	// first row
		m_matrix[0][0] * m.m_matrix[0][0] + m_matrix[0][1] * m.m_matrix[1][0] + m_matrix[0][2] * m.m_matrix[2][0],
		m_matrix[0][0] * m.m_matrix[0][1] + m_matrix[0][1] * m.m_matrix[1][1] + m_matrix[0][2] * m.m_matrix[2][1],
		m_matrix[0][0] * m.m_matrix[0][2] + m_matrix[0][1] * m.m_matrix[1][2] + m_matrix[0][2] * m.m_matrix[2][2]
	} 
	,
	{	// second row
		m_matrix[1][0] * m.m_matrix[0][0] + m_matrix[1][1] * m.m_matrix[1][0] + m_matrix[1][2] * m.m_matrix[2][0],
		m_matrix[1][0] * m.m_matrix[0][1] + m_matrix[1][1] * m.m_matrix[1][1] + m_matrix[1][2] * m.m_matrix[2][1],
		m_matrix[1][0] * m.m_matrix[0][2] + m_matrix[1][1] * m.m_matrix[1][2] + m_matrix[1][2] * m.m_matrix[2][2]
	}
	,
	{	// third row
		m_matrix[2][0] * m.m_matrix[0][0] + m_matrix[2][1] * m.m_matrix[1][0] + m_matrix[2][2] * m.m_matrix[2][0],
		m_matrix[2][0] * m.m_matrix[0][1] + m_matrix[2][1] * m.m_matrix[1][1] + m_matrix[2][2] * m.m_matrix[2][1],
		m_matrix[2][0] * m.m_matrix[0][2] + m_matrix[2][1] * m.m_matrix[1][2] + m_matrix[2][2] * m.m_matrix[2][2]
	}
	};
}

//	scalar multiplication
Matrix3x3& Matrix3x3::operator*=(real64 s)
{
	m_matrix[0][0] *= s;
	m_matrix[0][1] *= s;
	m_matrix[0][2] *= s;
	m_matrix[1][0] *= s;
	m_matrix[1][1] *= s;
	m_matrix[1][2] *= s;
	m_matrix[2][0] *= s;
	m_matrix[2][1] *= s;
	m_matrix[2][2] *= s;

	return *this;
}

// scalar division
Matrix3x3& Matrix3x3::operator/=(real64 s)
{
	m_matrix[0][0] /= s;
	m_matrix[0][1] /= s;
	m_matrix[0][2] /= s;
	m_matrix[1][0] /= s;
	m_matrix[1][1] /= s;
	m_matrix[1][2] /= s;
	m_matrix[2][0] /= s;
	m_matrix[2][1] /= s;
	m_matrix[2][2] /= s;

	return *this;
}

//////////////////////////////////////////////////////////////////////////
//					Getters

//////////////////////////////////////////////////////////////////////////
//	if zero, there is no inverse
real64 Matrix3x3::getdeterminant() const
{
	return 
		((m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2]) +
		(m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0]) +
		(m_matrix[0][2] * m_matrix[1][0] * m_matrix[2][1])) -
		((m_matrix[2][0] * m_matrix[1][1] * m_matrix[0][1]) +
		(m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2]) +
		(m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1]));
}

//////////////////////////////////////////////////////////////////////////
//	
Matrix3x3& Matrix3x3::invert()
{
	mat3 tmp = *this;
	real64 invdet = 1.0f / getdeterminant();
	m_matrix[0][0] = (tmp(1, 1)*tmp(2, 2) - tmp(2, 1)*tmp(1, 2))*invdet;
	m_matrix[0][1] = -(tmp(0, 1)*tmp(2, 2) - tmp(0, 2)*tmp(2, 1))*invdet;
	m_matrix[0][2] = (tmp(0, 1)*tmp(1, 2) - tmp(0, 2)*tmp(1, 1))*invdet;
	m_matrix[1][0] = -(tmp(1, 0)*tmp(2, 2) - tmp(1, 2)*tmp(2, 0))*invdet;
	m_matrix[1][1] = (tmp(0, 0)*tmp(2, 2) - tmp(0, 2)*tmp(2, 0))*invdet;
	m_matrix[1][2] = -(tmp(0, 0)*tmp(1, 2) - tmp(1, 0)*tmp(0, 2))*invdet;
	m_matrix[2][0] = (tmp(1, 0)*tmp(2, 1) - tmp(2, 0)*tmp(1, 1))*invdet;
	m_matrix[2][1] = -(tmp(0, 0)*tmp(2, 1) - tmp(2, 0)*tmp(0, 1))*invdet;
	m_matrix[2][2] = (tmp(0, 0)*tmp(1, 1) - tmp(1, 0)*tmp(0, 1))*invdet;

	return *this;
}

//////////////////////////////////////////////////////////////////////////
//	
Matrix3x3 Matrix3x3::getinverse() const
{
	mat3 tmp = *this;
	return tmp.invert();
}

//////////////////////////////////////////////////////////////////////////
//	
Matrix3x3& Matrix3x3::transpose()
{
	real64 
	tmp = m_matrix[0][1];
	m_matrix[0][1] = m_matrix[1][0];
	m_matrix[1][0] = tmp;
	tmp = m_matrix[0][2];
	m_matrix[0][2] = m_matrix[2][0];
	m_matrix[2][0] = tmp;
	tmp = m_matrix[1][2];
	m_matrix[1][2] = m_matrix[2][1];
	m_matrix[2][1] = tmp;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
//	
Matrix3x3 Matrix3x3::gettranspose() const
{
	mat3 return_mat = *this;
	return return_mat.transpose();
}

