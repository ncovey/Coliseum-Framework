//////////////////////////////////////////////////////////////////////////
//	vector container
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "iter.h"
#include <stdio.h>

///=======================================================================
//	Declaration:
///=======================================================================

namespace CF
{
namespace EGG
{
	template <typename T>
	class vector
	{
	public:

		class	const_iter;
		class	iter;

		vector<T>();
		~vector<T>();

		vector<T>(const vector<T>& copy);

		//////////////////////////////////////////////////////////////////////////
		//	Operator Overloads:

		// access
		virtual const T&			operator[](const uint32 idx) const;
		virtual T&					operator[](const uint32 idx);

		// assignment
		virtual vector<T>&			operator=(const vector<T>&);
		virtual bool				operator==(const vector<T>&);
		virtual bool				operator!=(const vector<T>&);
		// appends the new element at the end
		virtual const T&			operator+=(const T&);
		virtual T&					operator+=(T&&);
		// concatenates another container at the end of this one
		virtual const vector<T>&	operator+=(const vector<T>&);
		virtual vector<T>&			operator+=(vector<T>&&);

		//////////////////////////////////////////////////////////////////////////
		//	Methods:

		//	access:
		virtual const T&	at(const sz_t) const;
		virtual T&			at(const sz_t);

		virtual const T&	front() const;
		virtual T&			front();
		virtual const T&	back() const;
		virtual T&			back();

		//	container manipulation methods:
		virtual void		push_back(const T&);
		virtual	void		push_back(T&&);
		virtual void		pop_back();
		virtual void		push_front(const T&);
		virtual	void		push_front(T&&);
		virtual void		pop_front();

		//	removes all elements; size = 0
		virtual void		clear();
		virtual void		reserve(sz_t n);

		// resizes the container to contain n elements. if n is smaller than the current container size
		// the content is first reduced to its first n elements, removing those beyond and destroying them.
		virtual void		resize(sz_t n);
		// resizes the container to n elements
		virtual void		resize(sz_t n, const T& value);

		// request the container to condense its size.
		virtual void		shrink_to_fit();

		// getters:
		virtual sz_t&		size() const;
		virtual bool		empty() const;

		// returns an iter to the first instance, otherwise returns ::end()
		virtual const_iter	find(const T&) const;
		// returns an iter to the first instance, otherwise returns ::end()
		virtual iter		find(const T&);

		//////////////////////////////////////////////////////////////////////////
		//	Iterator Implementation:

		virtual const_iter	begin() const;
		virtual iter		begin();
		virtual const_iter	end() const;
		virtual iter		end();

		// inserts new elements before the specified position
		virtual void		insert(const_iter& position, const T& value);
		virtual void		insert(const_iter& position, T&& value);
		// inserts num_items before the position, initialized to value
		virtual void		insert(const_iter& position, uint32 num_items, const T& value);

		virtual void		insert(sz_t index, const T& value);
		virtual void		insert(sz_t index, T&& value);
		virtual void		insert(sz_t index, uint32 num_items, const T& value);

		virtual void		erase(const_iter&);
		virtual void		erase(const_iter& begin_at, const_iter& end_at);

		virtual void		erase(const sz_t);
		virtual void		erase(const sz_t begin_at, const sz_t end_at);

		//// The container is extended by inserting a new element at position. 
		//// This new element is constructed in place using args as the arguments for its construction. 
		//// This effectively increases the container size by one.
		//template<class... Args>
		//virtual iter		emplace(const_iter& position_at, Args&&... args);
		//// Inserts a new element at the end of the vector, right after its current last element.
		//// This new element is constructed in place using args as the arguments for its constructor.
		//template<class... Args>
		//virtual iter		emplace_back(const_iter& position_at, Args&&... args);

		// replaces the contents of the container with num_items all assigned to value
		virtual void		assign(uint32 num_items, const T& value);

		//void				swap(const container_type&);

		//template <typename T>
		//void swap(container<T>& lhs, container<T>& rhs);

	protected:

		sz_t num_elmts;		// # of elements contained
		sz_t sz_alloc;		// currently allocated space in bytes
		T *m_pData;			// data

	public:

		class iter : public __itr<T>
		{
		};

		class const_iter : public __const_itr<T>
		{
		};


<<<<<<< HEAD
=======

	}; // end class vector


>>>>>>> e2b4031a429e889093f06ec178c16e241673daec
///=======================================================================
//	Implementation:
///=======================================================================

/************************************************************************/
/* default ctor
/************************************************************************/
template <typename T>
vector<T>::vector()
	: num_elmts(0)
	, sz_alloc(0)
	, m_pData(nullptr)
{

}

/************************************************************************/
/* copy ctor
/************************************************************************/
template <typename T>
vector<T>::vector(const vector<T>& v)
	: num_elmts(v.num_elmts)
	, sz_alloc(v.sz_alloc)
	, m_pData(nullptr)
{
	*this = v; // invoke assignment operator
}

template <typename T>
vector<T>::~vector()
{
	clear();
}

template <typename T>
const T&
vector<T>::operator[](const uint32 idx) const
{
	return m_pData[idx];
}

template <typename T>
T&
vector<T>::operator[](const uint32 idx)
{
	return const_cast<T&>(static_cast<const vector<T>&>(*this)[idx]);
}


// assignment
template <typename T>
vector<T>&
vector<T>::operator=(const vector<T>& v)
{
	// empty out the current vector
	clear();

	if (v.m_pData != nullptr && v.num_elmts > 0 && v.sz_alloc > 0)
	{
		// allocate same amount of space:
		m_pData = new T[ (v.sz_alloc/sizeof(T)) ];
		// copy each element:
		for (sz_t i = 0; i < v.size(); ++i)
		{
			m_pData[i] = v[i];
		}
	}

	num_elmts = v.num_elmts;
	sz_alloc = v.sz_alloc;

	return *this;
}

//template <typename T>
//bool
//vector<T>::operator==(const vector<T>& v)
//{
//	if (size() != v.size())
//		return false;
//
//	for (sz_t i = 0; i < size(); ++i)
//		if ((*this)[i] != v[i])
//			return false;
//
//	return true;
//}
//
//template <typename T>
//bool
//vector<T>::operator!=(const vector<T>& v)
//{
//	return !(*this == v)
//}

//// appends the new element at the end
//template <typename T>
//const T&
//vector<T>::operator+=(const T& new_elmt)
//{
//	push_back(new_elmt);
//	return (*this)[size() - 1];
//}
//
//template <typename T>
//T&
//vector<T>::operator+=(T&& new_elmt)
//{
//	return const_cast<T&>(
//		static_cast<vector<T>&>(*this) += new_elmt);
//}

// concatenates another vector at the end of this one
//template <typename T>
//const vector<T>&
//vector<T>::operator+=(const vector<T>& v)
//{
//	sz_t old_size = size() - 1;
//	resize(size() + v.size(), T());
//	for (sz_t i = 0; i < v.size(); ++i)
//	{
//		(*this)[old_size + i] = v[i];
//	}
//	return *this;
//}
//
//template <typename T>
//vector<T>&
//vector<T>::operator+=(vector<T>&& v)
//{
//	return const_cast<vector<T>&>(
//		static_cast<vector<T>&>(*this) += v);
//	return *this;
//}

template <typename T>
const T&
vector<T>::at(const sz_t) const
{
	return (*this)[idx];
}

template <typename T>
T&
vector<T>::at(const sz_t idx)
{
	return const_cast<T&>(
		static_cast<vector<T>&>(*this).at(idx));
}

template <typename T>
const T&
vector<T>::front() const
{
	return (*this)[0];
}

template <typename T>
T&
vector<T>::front()
{
	return const_cast<T&>(
		static_cast<vector<T>&>(*this).front());
}

template <typename T>
const T&
vector<T>::back() const
{
	return (*this)[size() - 1];
}

template <typename T>
T&
vector<T>::back()
{
	return const_cast<T&>(
		static_cast<vector<T>&>(*this).back());
}


template <typename T>
void
vector<T>::push_back(const T& new_elmt)
{
	if (size() + 1 > (sz_alloc / sizeof(T)))
	{
		resize(2 * size());
	}
	(*this)[num_elmts] = new_elmt;
	++num_elmts;
}

template <typename T>
void
vector<T>::push_back(T&& new_elmt)
{
	push_back(new_elmt); // ?
}

template <typename T>
void
vector<T>::pop_back()
{
	(*this)[--num_elmts]::~T();
}

template <typename T>
void
vector<T>::push_front(const T&)
{

}

template <typename T>
void
vector<T>::push_front(T&&)
{

}

template <typename T>
void
vector<T>::pop_front()
{

}

template <typename T>
void
vector<T>::clear()
{
	if (m_pData != nullptr)
	{
		delete[] m_pData;
		m_pData = nullptr;
	}
	num_elmts = 0;
	sz_alloc = 0;
}

template <typename T>
void
vector<T>::reserve(sz_t n)
{

}

// resizes the vector to contain n elements. if n is smaller than the current vector size
// the content is first reduced to its first n elements, removing those beyond and destroying them.
template <typename T>
void
vector<T>::resize(sz_t n)
{

}

// resizes the vector to n elements
template <typename T>
void
vector<T>::resize(sz_t n, const T& value)
{

}

// requests the vector to condense its size.
template <typename T>
void
vector<T>::shrink_to_fit()
{

}

template <typename T>
CF::sz_t&
vector<T>::size() const
{
	return num_elmts;
}

template <typename T>
bool
vector<T>::empty() const
{
	return num_elmts != 0;
}

// returns an iter to the first instance, otherwise returns ::end()
template <typename T>
vector<T>::iter
vector<T>::find(const T&)
{

}

// returns an iter to the first instance, otherwise returns ::end()
template <typename T>
vector<T>::const_iter
vector<T>::find(const T&) const
{

}

template <typename T>
vector<T>::iter
vector<T>::begin()
{

}

template <typename T>
vector<T>::const_iter
vector<T>::begin() const
{

}

template <typename T>
vector<T>::iter
vector<T>::end()
{

}

template <typename T>
vector<T>::const_iter
vector<T>::end() const
{

}

// inserts new elements before the specified position
template <typename T>
void
vector<T>::insert(vector<T>::const_iter& position, const T& value)
{

}

// inserts new elements before the specified position
template <typename T>
void
vector<T>::insert(vector<T>::const_iter& position, T&& value)
{

}

// inserts num_items before the position, initialized to value
template <typename T>
void
vector<T>::insert(vector<T>::const_iter& position, uint32 num_items, const T& value)
{

}

template <typename T>
void
vector<T>::insert(sz_t index, const T& value)
{

}

template <typename T>
void
vector<T>::insert(sz_t index, T&& value)
{

}

template <typename T>
void
vector<T>::insert(sz_t index, uint32 num_items, const T& value)
{

}

template <typename T>
void
vector<T>::erase(vector<T>::const_iter&)
{

}

template <typename T>
void
vector<T>::erase(vector<T>::const_iter& begin_at, vector<T>::const_iter& end_at)
{

}

template <typename T>
void
vector<T>::erase(const sz_t)
{

}

template <typename T>
void
vector<T>::erase(const sz_t begin_at, const sz_t end_at)
{

}

// replaces the contents of the vector with num_items all assigned to value
template <typename T>
void
vector<T>::assign(uint32 num_items, const T& value)
{

}

template <typename T>
void
vector<T>::swap(const vector<T>&)
{

}



} // end namespace EGG
} // end namespace CF