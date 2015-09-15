//	fast math .h
//	
//	math operations that prioritize performance over accuracy
//	some operations are redundant redefinitions found in the standard math or cmath header
//	but are reimplemented here to avoid including those headers.
//	where templates might be helpful, they are not used because typing function<type>(...) is annoying,
//	and may allow for some undefined behavior.

#pragma once

#include "types.h"

namespace CF
{

namespace AfterMath
{

// absolute value

inline	int32		abs(int32 value);
inline	int64		abs(int64 value);
inline	real32		abs(real32 value);
inline	real64		abs(real64 value);

inline	int32		fpow(int32 base, uint32 power);
		real32		fpow(int32 base, int32 power);
inline	real32		fpow(real32 base, int32 power);
		real64		fpow(real64 base, real64 power);

		real32		fsqrt(real32 value);
		real32		frsqrt(real32 value);

		real32		fln(real32 value);

// inline real32 fsin(real32 value);
// inline real32 farcsin(real32 value);
// inline real32 fcos(real32 value);
// inline real32 farccos(real32 value);
// inline real32 ftan(real32 value);
// inline real32 farctan(real32 value);

}

}