//////////////////////////////////////////////////////////////////////////
//	vector container
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "container.h"
#include <stdio.h>

namespace CF
{
namespace EGG
{
	///=======================================================================
	//	Declaration:
	///=======================================================================

	template <typename T>
	class vector : public container<T>
	{
	public:

		vector<T>();
		~vector<T>();

		vector<T>(const vector<T>& v);

		class iter : public __itr<T>
		{};

		class const_iter : public __const_itr<T>
		{};

	protected:

		sz_t num_elmts;		// # of elements contained
		sz_t sz_alloc;		// currently allocated space in bytes
		T *m_pData;			// data

	}; // end class vector

} // end namespace EGG
} // end namespace CF



///=======================================================================
//	Implementation:
///=======================================================================

/************************************************************************/
/* default ctor
/************************************************************************/
template <typename T>
CF::EGG::vector<T>::vector()
	: num_elmts(0)
	, sz_alloc(0)
	, m_pData(nullptr)
{

}

/************************************************************************/
/* copy ctor
/************************************************************************/
template <typename T>
CF::EGG::vector<T>::vector(const vector<T>& v)
	: num_elmts(v.num_elmts)
	, sz_alloc(v.sz_alloc)
	, m_pData(nullptr)
{
	*this = v; // invoke assignment operator
}

template <typename T>
CF::EGG::vector<T>::~vector()
{
	clear();
}

template <typename T>
const T&
CF::EGG::vector<T>::operator[](const uint32 idx) const
{
	return m_pData[idx];
}

template <typename T>
T&
CF::EGG::vector<T>::operator[](const uint32 idx)
{
	return const_cast<T&>(static_cast<const CF::EGG::vector<T>&>(*this)[idx]);
}


// assignment
template <typename T>
CF::EGG::vector<T>&
CF::EGG::vector<T>::operator=(const CF::EGG::vector<T>& v)
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

template <typename T>
bool
CF::EGG::vector<T>::operator==(const CF::EGG::vector<T>& v)
{
	if (size() != v.size())
		return false;

	for (sz_t i = 0; i < size(); ++i)
		if ((*this)[i] != v[i])
			return false;

	return true;
}

template <typename T>
bool
CF::EGG::vector<T>::operator!=(const CF::EGG::vector<T>& v)
{
	return !(*this == v)
}

// appends the new element at the end
template <typename T>
const T&
CF::EGG::vector<T>::operator+=(const T& new_elmt)
{
	push_back(new_elmt);
	return (*this)[size() - 1];
}

template <typename T>
T&
CF::EGG::vector<T>::operator+=(T&& new_elmt)
{
	return const_cast<T&>(
		static_cast<CF::EGG::vector<T>&>(*this) += new_elmt);
}

// concatenates another CF::EGG::vector at the end of this one
template <typename T>
const CF::EGG::vector<T>&
CF::EGG::vector<T>::operator+=(const CF::EGG::vector<T>& v)
{
	sz_t old_size = size() - 1;
	resize(size() + v.size(), T());
	for (sz_t i = 0; i < v.size(); ++i)
	{
		(*this)[old_size + i] = v[i];
	}
	return *this;
}

template <typename T>
CF::EGG::vector<T>&
CF::EGG::vector<T>::operator+=(CF::EGG::vector<T>&& v)
{
	return const_cast<CF::EGG::vector<T>&>(
		static_cast<CF::EGG::vector<T>&>(*this) += v);
	return *this;
}

template <typename T>
const T&
CF::EGG::vector<T>::at(const sz_t) const
{
	return (*this)[idx];
}

template <typename T>
T&
CF::EGG::vector<T>::at(const sz_t idx)
{
	return const_cast<T&>(
		static_cast<CF::EGG::vector<T>&>(*this).at(idx));
}

template <typename T>
const T&
CF::EGG::vector<T>::front() const
{
	return (*this)[0];
}

template <typename T>
T&
CF::EGG::vector<T>::front()
{
	return const_cast<T&>(
		static_cast<CF::EGG::vector<T>&>(*this).front());
}

template <typename T>
const T&
CF::EGG::vector<T>::back() const
{
	return (*this)[size() - 1];
}

template <typename T>
T&
CF::EGG::vector<T>::back()
{
	return const_cast<T&>(
		static_cast<CF::EGG::vector<T>&>(*this).back());
}


template <typename T>
void
CF::EGG::vector<T>::push_back(const T& new_elmt)
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
CF::EGG::vector<T>::push_back(T&& new_elmt)
{
	push_back(new_elmt); // ?
}

template <typename T>
void
CF::EGG::vector<T>::pop_back()
{

}

template <typename T>
void
CF::EGG::vector<T>::push_front(const T&)
{

}

template <typename T>
void
CF::EGG::vector<T>::push_front(T&&)
{

}

template <typename T>
void
CF::EGG::vector<T>::pop_front()
{

}

template <typename T>
void
CF::EGG::vector<T>::clear()
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
CF::EGG::vector<T>::reserve(sz_t n)
{

}

// resizes the CF::EGG::vector to contain n elements. if n is smaller than the current CF::EGG::vector size
// the content is first reduced to its first n elements, removing those beyond and destroying them.
template <typename T>
void
CF::EGG::vector<T>::resize(sz_t n)
{

}

// resizes the CF::EGG::vector to n elements
template <typename T>
void
CF::EGG::vector<T>::resize(sz_t n, const T& value)
{

}

// requests the CF::EGG::vector to condense its size.
template <typename T>
void
CF::EGG::vector<T>::shrink_to_fit()
{

}

template <typename T>
sz_t
CF::EGG::vector<T>::size() const
{

}

template <typename T>
bool
CF::EGG::vector<T>::empty() const
{

}

// returns an iter to the first instance, otherwise returns ::end()
template <typename T>
iter
CF::EGG::vector<T>::find(const T&)
{

}

// returns an iter to the first instance, otherwise returns ::end()
template <typename T>
const_iter
CF::EGG::vector<T>::find(const T&) const
{

}

template <typename T>
iter
CF::EGG::vector<T>::begin()
{

}

template <typename T>
const_iter
CF::EGG::vector<T>::begin() const
{

}

template <typename T>
iter
CF::EGG::vector<T>::end()
{

}

template <typename T>
const_iter
CF::EGG::vector<T>::end() const
{

}

// inserts new elements before the specified position
template <typename T>
void
CF::EGG::vector<T>::insert(const_iter& position, const T& value)
{

}

// inserts new elements before the specified position
template <typename T>
void
CF::EGG::vector<T>::insert(const_iter& position, T&& value)
{

}

// inserts num_items before the position, initialized to value
template <typename T>
void
CF::EGG::vector<T>::insert(const_iter& position, uint32 num_items, const T& value)
{

}

template <typename T>
void
CF::EGG::vector<T>::insert(sz_t index, const T& value)
{

}

template <typename T>
void
CF::EGG::vector<T>::insert(sz_t index, T&& value)
{

}

template <typename T>
void
CF::EGG::vector<T>::insert(sz_t index, uint32 num_items, const T& value)
{

}

template <typename T>
void
CF::EGG::vector<T>::erase(const_iter&)
{

}

template <typename T>
void
CF::EGG::vector<T>::erase(const_iter& begin_at, const_iter& end_at)
{

}

template <typename T>
void
CF::EGG::vector<T>::erase(const sz_t)
{

}

template <typename T>
void
CF::EGG::vector<T>::erase(const sz_t begin_at, const sz_t end_at)
{

}

// replaces the contents of the CF::EGG::vector with num_items all assigned to value
template <typename T>
void
CF::EGG::vector<T>::assign(uint32 num_items, const T& value)
{

}

template <typename T>
void
CF::EGG::vector<T>::swap(const CF::EGG::vector<T>&)
{

}