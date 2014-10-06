// string

#pragma once

namespace CF
{

namespace EGG
{
	class str
	{
	public:
		// ctor
		str();
		str(const str&);
		// dtor
		~str();
		
		//////////////////////////////////////////////////////////////////////////
		// operator overloads
		str& operator=(const str&);
		str& operator=(const char*);
		str& operator=(const char);
		str& operator+=(const str&);
		str& operator+=(const char*);
		str& operator+=(const char);
		const char& operator[](const unsigned int) const;
		char& operator[](const unsigned int);

		//////////////////////////////////////////////////////////////////////////
		// getters
		unsigned int size() const;
		const char* c_str() const;
		// uppercase
		str& getupper() const;
		// lowercase
		str& getlower() const;
		// get part of string
		const str& substr(unsigned int begin, unsigned int end) const;

		// case-sensitive
		bool haschar(const char) const;
		// not case-sensitive
		bool hasncasechar(const char) const;
		// case-sensitive
		bool hasstr(const str&) const;
		bool hasstr(const char*) const;
		// not case-sensitive
		bool hasncasestr(const str&) const;
		bool hasncasestr(const char*) const;
		
		// returns index of first instance, -1 if not found
		int findchar(const char) const;
		// returns index of first char of the str in the str
		int findstr(const str&) const;
		int findstr(const char*) const;
		
		//////////////////////////////////////////////////////////////////////////
		// manipulators
		void clear();
		// uppercase
		str& makeupper();
		// lowercase
		str& makelower();
		// removes the first chars
		void truncfront(unsigned int numChars);
		// removes the last chars
		void truncback(unsigned int numChars);

		// replace part of the string
		void replace(unsigned int begin, unsigned int end, const str&);
		void replace(unsigned int begin, unsigned int end, const char*);

		// removes the character at the index
		void remove(unsigned int);
		// removes all instances of the character
		void remove(const char);
		// removes all instances of the string
		void remove(const str&);
		void remove(const char*);

	private:
		unsigned int m_size;
		// array of characters
		char* m_cData;
	};
}

}