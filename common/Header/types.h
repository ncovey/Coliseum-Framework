#pragma once

//	This might be useful in the future, but at the moment, there is
//	no compelling reason to do this other than to have different primitive type names.
//	However, they can be changed in a single place, here, if there are platform dependent issues.

// Maybe will add more data types later on. Not sure if I should use macros here.

namespace CF
{

	typedef		signed		__int8		int8;
	typedef		unsigned	__int8		uint8;
	typedef		signed		__int16		int16;
	typedef		unsigned	__int16		uint16;
	typedef		signed		__int32		int32;
	typedef		unsigned	__int32		uint32;
	typedef		signed		__int64		int64;
	typedef		unsigned	__int64		uint64;
	
	typedef					float		real32;
	typedef					double		real64;

	typedef		unsigned	char		char8;

	typedef		uint32					sz_t;	// size
	
	typedef		void*					v_ptr;

	//typedef					bool		boolean;

}
