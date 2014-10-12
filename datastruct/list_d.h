//////////////////////////////////////////////////////////////////////////
//	list_d.h
//////////////////////////////////////////////////////////////////////////

#pragma once

namespace CF
{
namespace EGG
{
	// Doubly-Linked List
	template <typename T>
	class list_d
	{
	public:
		// ctor
		list_d<T>();
		list_d<T>(const list_d<T>&);
		
		// dtor
		~list_d<T>();

		// operator overloads:
		// assignment operator
		list_d<T>& operator=(const list_d<T>);
		// element access operator
		const T& operator[](const unsigned int) const;
		T& operator[](const unsigned int);
		
		// getters
		unsigned int size() const;
		T& front();
		T& back();

		// manipulators
		void clear();
		void appendback(const T&);
		void appendfront(const T&);
		T& removeback();
		T& removefront();

		// TODO: need iterator
		//void insertBefore(const T& toInsert, const );

	private:
		struct node
		{
			T *m_next, *m_prev;
			node();
			node(const node&);
			~node();
			node& operator=(const node&);
		};
		// number of elements in list
		unsigned int m_size;
		// pointer past the last element (NULL)
		T* m_end;
		// array of nodes pointing to data of type T
		node* m_Data;
	};
}

}

//////////////////////////////////////////////////////////////////////////
//	Doubly-Linked List Implementation

//////////////////////////////////////////////////////////////////////////
//	ctor

// default ctor
template<typename T>
CF::EGG::list_d<T>::list_d()
	: m_size(0)
	, m_end(nullptr)
	, m_Data(nullptr)
{

}

// copy ctor
template<typename T>
CF::EGG::list_d<T>::list_d(const list_d<T>& ld)
	: m_size(ld.m_size)
	, m_end(ld.m_end)
	, m_Data(ld.m_Data)
{

}

template<typename T>
CF::EGG::list_d<T>::~list_d()
{

}