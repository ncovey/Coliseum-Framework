// fast math .cpp

#include "types.h"
#include "constants.h"
#include "fastmath.h"
#include <xmmintrin.h>

using namespace CF;
using namespace AfterMath;

// acceptable amount of error
const real64 AFTERMATH_APPROXIMATION_PRECISION = 5e-7;

//////////////////////////////////////////////////////////////////////////
// absolute value
#define AFTERMATH_FASTMATH_ABS(x) { return (x < 0) ? -x : x; }
inline int32	AfterMath::abs(int32 value)		{ AFTERMATH_FASTMATH_ABS(value); }
inline int64	AfterMath::abs(int64 value)		{ AFTERMATH_FASTMATH_ABS(value); }
inline real32	AfterMath::abs(real32 value)	{ AFTERMATH_FASTMATH_ABS(value); }
inline real64	AfterMath::abs(real64 value)	{ AFTERMATH_FASTMATH_ABS(value); }

//	take integer base to positive integer power
//	the goal is to get the compiler to replace
//	pow(value, 4)
//	with:
//	value*value*value*value*1
//	hopefully it should "unwind" the inline function calls rather jumping to an actual callback
//	how do I know it's doing that??? (look at disassembly)
inline int32 
AfterMath::fpow(int32 base, uint32 power)
{
	return ((power > 0) ? base * AfterMath::fpow(base, power - 1) : 1);
}

inline real32
AfterMath::fpow(real32 base, int32 power)
{
	real32 retVal(1);
	for (size_t i = 0; i < power; i++)
	{
		retVal *= base;
	}
	return retVal;
}

// take integer base to negative integer power (results in fraction)
real32 
AfterMath::fpow(int32 base, int32 power)
{
	return 1.0f / ((power < 0) ? AfterMath::fpow(base, static_cast<uint32>(AfterMath::abs(power))) : 1);
}

// take a base to an irrational power
real64
AfterMath::fpow(real64 base, real64 power)
{
	// Taylor series approx
	real64 p = power * AfterMath::fln(base);
	return 1.0f + p + (p*p) / 2.0f + (p*p*p) / 6.0f + (p*p*p*p) / 24.0f + (p*p*p*p*p) / 120.0f + (p*p*p*p*p*p) / 720 + (p*p*p*p*p*p*p) / 5040.0f + (p*p*p*p*p*p*p*p) / 40320.0f + (p*p*p*p*p*p*p*p*p) / 362880.0f;
}

// square root
real32 
AfterMath::fsqrt(real32 value)
{
	__m128 in = _mm_load_ss(&value);
	real32 pOut (0.0f);
	_mm_store_ss(&pOut, _mm_mul_ss(in, _mm_rsqrt_ss(in)));
	return pOut;
	//return 1 / AfterMath::frsqrt(value);
}

//	fast inverse (reverse) square root
real32 
AfterMath::frsqrt(real32 value)
{
	return (1 / fsqrt(value));

	//int64 i;
	//real64 x2, y;
	//const real64 threehalfs = 1.5F;

	//x2 = value * 0.5F;
	//y = value;
	//i = *(int64 *)&y;					// evil floating point bit level hacking
	//i = 0x5f3759df - (i >> 1);          // what the f**k?
	//y = *(real64 *)&i;
	//y *= (threehalfs - (x2 * y * y));   // 1st iteration
	////y *= (threehalfs - (x2 * y * y));   // 2nd iteration, this can be removed
	//return y;
}

//////////////////////////////////////////////////////////////////////////
//	Natural Log
// taken from here:
//	http://stackoverflow.com/questions/3343395/value-of-natural-logarithm
//
real32 
AfterMath::fln(real32 value)
{
	uint32 b = 0;
	while (value > 10)
	{
		value /= 10;
		b++;
	}

	real64 ty = (value - 1) / (value + 1);
	real64 p = ty * ty;
	real64 logx(0), tty(0);
	int i = 1;
	do {
		logx += ty / i;
		tty = ty;
		ty *= p;
		i += 2;
	} while (((tty / (i - 2)) - (ty / i)) > AFTERMATH_APPROXIMATION_PRECISION);

	return 2.0f*logx + b*2.30258509299f;
}