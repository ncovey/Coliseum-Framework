//////////////////////////////////////////////////////////////////////////
//	vector container
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "container.h"

namespace CF
{
namespace EGG
{
	//////////////////////////////////////////////////////////////////////////
	//	Declaration:

	template<typename T>
	class vector : public container<T>
	{
	public:

		vector<T>();
		~vector<T>();

		vector<T>(const vector<T>& v);

	protected:

		sz_t num_elmts;
		T *m_elmts;

	}; // end class vector

} // end namespace EGG
} // end namespace CF



//////////////////////////////////////////////////////////////////////////
//	Implementation:

template<typename T>
CF::EGG::vector<T>::vector()
	: num_elmts(0)
	, m_elmts(nullptr)
{

}

template<typename T>
CF::EGG::vector<T>::vector(const vector<T>& v)
	: num_elmts(v.num_elmts)
	, m_elmts(v.m_elmts)
{

}

template<typename T>
CF::EGG::vector<T>::~vector()
{
	delete m_elmts;
	num_elmts = 0;
}

template<typename T>
T&
CF::EGG::vector<T>::operator[](const uint32 idx)
{

}

template<typename T>
const T&
CF::EGG::vector<T>::operator[](const uint32 idx) const
{

}

// assignment
template<typename T>
container<T>&
CF::EGG::vector<T>::operator=(const container<T>&)
{

}

template<typename T>
bool
CF::EGG::vector<T>::operator==(const container<T>&)
{

}

template<typename T>
bool
CF::EGG::vector<T>::operator!=(const container<T>&)
{

}

// appends the new element at the end
template<typename T>
const T&
CF::EGG::vector<T>::operator+=(const T&)
{

}

template<typename T>
T&
CF::EGG::vector<T>::operator+=(T&&)
{

}

// concatenates another container at the end of this one
template<typename T>
const container<T>&
CF::EGG::vector<T>::operator+=(const container<T>&)
{

}

template<typename T>
container<T>&
CF::EGG::vector<T>::operator+=(container<T>&&)
{

}

template<typename T>
T&
CF::EGG::vector<T>::at(const index_t)
{

}

template<typename T>
const T&
CF::EGG::vector<T>::at(const index_t) const
{

}

template<typename T>
T&
CF::EGG::vector<T>::front()
{

}

template<typename T>
const T&
CF::EGG::vector<T>::front() const
{

}

template<typename T>
T&
CF::EGG::vector<T>::back()
{

}

template<typename T>
const T&
CF::EGG::vector<T>::back() const
{

}

template<typename T>
void
CF::EGG::vector<T>::push_back(const T&)
{

}

template<typename T>
void
CF::EGG::vector<T>::push_back(T&&)
{

}

template<typename T>
void
CF::EGG::vector<T>::pop_back()
{

}

template<typename T>
void
CF::EGG::vector<T>::push_front(const T&)
{

}

template<typename T>
void
CF::EGG::vector<T>::push_front(T&&)
{

}

template<typename T>
void
CF::EGG::vector<T>::pop_front()
{

}

template<typename T>
void
CF::EGG::vector<T>::clear()
{

}

template<typename T>
void
CF::EGG::vector<T>::reserve(sz_t n)
{

}

// resizes the container to contain n elements. if n is smaller than the current container size
// the content is first reduced to its first n elements, removing those beyond and destroying them.
template<typename T>
void
CF::EGG::vector<T>::resize(sz_t n)
{

}

// resizes the container to n elements
template<typename T>
void
CF::EGG::vector<T>::resize(sz_t n, const T& value)
{

}

// requests the container to condense its size.
template<typename T>
void
CF::EGG::vector<T>::shrink_to_fit()
{

}

template<typename T>
sz_t
CF::EGG::vector<T>::size() const
{

}

template<typename T>
bool
CF::EGG::vector<T>::empty() const
{

}

// returns an iter to the first instance, otherwise returns ::end()
template<typename T>
iter
CF::EGG::vector<T>::find(const T&)
{

}

// returns an iter to the first instance, otherwise returns ::end()
template<typename T>
const_iter
CF::EGG::vector<T>::find(const T&) const
{

}

template<typename T>
iter
CF::EGG::vector<T>::begin()
{

}

template<typename T>
const_iter
CF::EGG::vector<T>::begin() const
{

}

template<typename T>
iter
CF::EGG::vector<T>::end()
{

}

template<typename T>
const_iter
CF::EGG::vector<T>::end() const
{

}

// inserts new elements before the specified position
template<typename T>
void
CF::EGG::vector<T>::insert(const_iter& position, const T& value)
{

}

// inserts new elements before the specified position
template<typename T>
void
CF::EGG::vector<T>::insert(const_iter& position, T&& value)
{

}

// inserts num_items before the position, initialized to value
template<typename T>
void
CF::EGG::vector<T>::insert(const_iter& position, uint32 num_items, const T& value)
{

}

template<typename T>
void
CF::EGG::vector<T>::insert(index_t index, const T& value)
{

}

template<typename T>
void
CF::EGG::vector<T>::insert(index_t index, T&& value)
{

}

template<typename T>
void
CF::EGG::vector<T>::insert(index_t index, uint32 num_items, const T& value)
{

}

template<typename T>
void
CF::EGG::vector<T>::erase(const_iter&)
{

}

template<typename T>
void
CF::EGG::vector<T>::erase(const_iter& begin_at, const_iter& end_at)
{

}

template<typename T>
void
CF::EGG::vector<T>::erase(const index_t)
{

}

template<typename T>
void
CF::EGG::vector<T>::erase(const index_t begin_at, const index_t end_at)
{

}

// replaces the contents of the container with num_items all assigned to value
template<typename T>
void
CF::EGG::vector<T>::assign(uint32 num_items, const T& value)
{

}

template<typename T>
void
CF::EGG::vector<T>::swap(const container<T>&)
{

}