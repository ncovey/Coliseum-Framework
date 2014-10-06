//////////////////////////////////////////////////////////////////////////
//	list_s.h
//////////////////////////////////////////////////////////////////////////

#pragma once

namespace CF
{
namespace EGG
{

	//////////////////////////////////////////////////////////////////////////
	//	Singly-Linked List
	template<typename T>
	class list_s
	{
	public:

		//////////////////////////////////////////////////////////////////////////
		//	ctors/dtors
		list_s<T>();
		list_s<T>(const list_s<T>&);
		~list_s<T>();

		//////////////////////////////////////////////////////////////////////////
		//	operators

		list_s<T>& operator=(const list_s<T>&);

		const T& operator[](const unsigned int) const;
		T& operator[](const unsigned int);

		//////////////////////////////////////////////////////////////////////////
		// getters
		bool empty() const;
		unsigned int size() const;
		T& front();
		T& back();

		//////////////////////////////////////////////////////////////////////////
		// manipulators

		void clear();
		void appendback(const T&);
		void appendfront(const T&);
		T& removeback();
		T& removefront();

		void insertafter(unsigned int idx);

	private:

		//////////////////////////////////////////////////////////////////////////
		//	node to hold data and location of next item in list
		struct node
		{
			T *m_Data;
			node *m_next;
		};

		// number of elements
		unsigned int m_size;
		// first node
		node *m_root;

	}; // end of class list_s
}
}