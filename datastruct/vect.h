//////////////////////////////////////////////////////////////////////////
//	vect.h
//////////////////////////////////////////////////////////////////////////

#pragma once

namespace CF
{
namespace EGG
{
	//////////////////////////////////////////////////////////////////////////
	//	vect
	//		data struct with dynamically re-sizable array
	template <typename T>
	class vect
	{
	public:
		// ctor
		vect<T>();
		// ctor: initialize vector with capacity (in bytes)
		vect<T>(unsigned int capacity);
		// copy ctor
		vect<T>(const vect<T>& vect);
		// dtor
		~vect<T>();

		// ***** operator overloads *****

		// assignment operator
		vect<T>& operator=(const vect<T>& v);
		// index access operator
		const T& operator[](unsigned int idx) const;
		T& operator[](unsigned int idx);

		// concatenates a vector onto the end of this one
		vect<T>& operator+=(const vect<T>& v);
		// same as pushback
		vect<T>& operator+=(const T& item);

		// ***** getters *****
		bool empty() const;
		unsigned int size() const;
		unsigned int capacity() const;

		// ***** manipulators *****

		// empties everything
		void clear();
		// removes space reserved for adding new elements
		void condense();
		// simple check to see if there is enough space in the array
		void ensure_capacity();
		// re-allocates reserved capacity of array in terms of the number of elements (size)
		void resize(unsigned int max_num_elements);

		// append a new element to the back of the array
		void pushback(const T&);
		// append a new element to the front of the array
		void pushfront(const T&);

		// insert before the provided index
		void insertbefore(unsigned int idx, const T& item);
		// insert after the provided index
		void insertafter(unsigned int idx, const T& item);

		// removes last element
		T& removeback();
		// removes first element
		T& removefront();

		// removes element at index
		T& remove(unsigned int idx);

	private:

		// re-allocates reserved capacity of array in terms bytes
		void resize_capacity(unsigned int new_capacity_bytes);

		// number of elements in array
		unsigned int m_size;
		// amount of memory vector array (in bytes)
		unsigned int m_capacity;
		// array of data
		T *m_Data;

	}; // end of class vect
}

}

//////////////////////////////////////////////////////////////////////////
//					Vector Implementation

//////////////////////////////////////////////////////////////////////////
// ctor

// default ctor
template <typename T>
CF::EGG::vect<T>::vect()
	: m_size(0)
	, m_capacity(0)
	, m_Data(nullptr)
{

}

template <typename T>
CF::EGG::vect<T>::vect(unsigned int preallocate_num_elements)
	: m_size(0)
	, m_capacity(capacity)
	, m_Data(nullptr)
{
	// ensure capacity
	m_Data = new T[preallocate_num_elements];
}

// copy ctor
template <typename T>
CF::EGG::vect<T>::vect(const CF::EGG::vect<T>& vect)
	: m_size(0)
	, m_capacity(0)
	, m_Data(nullptr)
{
	*this = vect;
}

//////////////////////////////////////////////////////////////////////////
//	dtor
//	calls clear()
template <typename T>
CF::EGG::vect<T>::~vect()
{
	clear();
}

//////////////////////////////////////////////////////////////////////////
//			Assignment operator

template <typename T>
CF::EGG::vect<T>& CF::EGG::vect<T>::operator=(const CF::EGG::vect<T>& v)
{
	// TODO: maybe implement copy-swap idiom

	// remove the existing data
	clear();
		
	if (v.m_Data != nullptr || v.m_size != 0 || v.m_capacity != 0)
	{
		// allocate space equal to the data from the vector being copied
		m_Data = new T[v.m_size];
		// copy
		for (unsigned int i = 0; i < v.size(); i++)
		{
			m_Data[i] = v[i];
		}
	}
	else
	{	// make it null instead of garbage
		m_Data = nullptr;
	}

	m_size = v.m_size;
	// actual capacity
	m_capacity = v.m_size * sizeof(T);

	return *this;
}

//////////////////////////////////////////////////////////////////////////
//			operators

// const ver.
template <typename T>
const T& CF::EGG::vect<T>::operator[](unsigned int idx) const
{
	return m_Data[idx];
}

// non-const ver.
template <typename T>
T& CF::EGG::vect<T>::operator[](unsigned int idx)
{	// call the const version of operator[]
	return const_cast<T&>(static_cast<const vect<T>&>(*this)[idx]);
}

//////////////////////////////////////////////////////////////////////////
//	operator+=
//	concatenates another vector onto this one
template <typename T>
CF::EGG::vect<T>& CF::EGG::vect<T>::operator+=(const CF::EGG::vect<T>& v)
{
	if (((m_size + v.m_size) * sizeof(T)) > m_capacity)
	{
		resize(m_size + v.m_size);
	}
	for (unsigned int i = 0; i < v.m_size; i++)
	{
		m_Data[m_size++] = v[i];
	}
	return *this;
}

//////////////////////////////////////////////////////////////////////////
//	operator+=
//	same as pushback(): appends a new item to the end of this vector
template <typename T>
CF::EGG::vect<T>& CF::EGG::vect<T>::operator+=(const T& item)
{
	pushback(item);
	return *this;
}

//////////////////////////////////////////////////////////////////////////
//			Getters

//	empty(): are there elements in vector?
template <typename T>
bool CF::EGG::vect<T>::empty() const
{
	return ! (m_size > 0);
}

//	size(): number of elements in vector
template <typename T>
unsigned int CF::EGG::vect<T>::size() const
{
	return m_size;
}

//	capacity(): occupation in memory (bytes) of internal data struct
template <typename T>
unsigned int CF::EGG::vect<T>::capacity() const
{
	return m_capacity;
}

//////////////////////////////////////////////////////////////////////////
//			Manipulators

//////////////////////////////////////////////////////////////////////////
//	clear()
//	Deletes internal data structure. Sets size and capacity to 0.
template <typename T>
void CF::EGG::vect<T>::clear()
{
	if (m_Data != nullptr)
	{
		delete[] m_Data;
		m_Data = nullptr;
	}
	m_size = 0;
	m_capacity = 0;
}

//////////////////////////////////////////////////////////////////////////
//	shrink()
//	removes reserved space. 
//	inefficient on space (during execution) because duplicates existing vector
//	in order to reallocate the space, then cleans up the vector
template <typename T>
void CF::EGG::vect<T>::condense()
{
	// if there are elements
	if (m_size > 0 && m_capacity > 0)
	{
		// if the size of the array isn't already exact
		if (m_capacity != (m_size * sizeof(T)))
		{
			CF::EGG::vect<T> tmp = *this; // copy
			clear(); // empty
			*this = tmp; // reassign
		}
	}

}

//////////////////////////////////////////////////////////////////////////
//	ensure_capacity
template <typename T>
void CF::EGG::vect<T>::ensure_capacity()
{
	// if adding an element would exceed the capacity of the array:
	if ((m_size + 1) > (m_capacity / sizeof(T)))
	{
		// resize it by doubling the existing capacity
		resize((m_size > 0) ? m_size * 2 : 2);
	}
}

//////////////////////////////////////////////////////////////////////////
//			Insertion

//////////////////////////////////////////////////////////////////////////
//	pushback()
//	add element to back
template <typename T>
void CF::EGG::vect<T>::pushback(const T& item)
{
	ensure_capacity();

	// add the element to the next available index in array
	m_Data[m_size++] = item;
}

//////////////////////////////////////////////////////////////////////////
//	add element to front:
//	SLOW! needs to shift entire block of vector data in order to add an element to the front
template <typename T>
void CF::EGG::vect<T>::pushfront(const T& item)
{
	ensure_capacity();

	// shift each element back one
	for (unsigned int i = m_size; i > 0; i--)
	{
		m_Data[i] = m_Data[i - 1];
	}

	// put the new item at the beginning:
	m_Data[0] = item;

	// increase
	m_size++;
}

//////////////////////////////////////////////////////////////////////////
//	insertbefore()
//	This is a weird function. If you insert something before index 4, then
//	whatever was at index 3 is now at index 4, and so on. You should probably use insertafter() instead.
template <typename T>
void CF::EGG::vect<T>::insertbefore(unsigned int idx, const T& item)
{
	ensure_capacity();

	// shift each element back one
	for (unsigned int i = m_size; i > idx; i--)
	{
		m_Data[i] = m_Data[i - 1];
	}

	// put the new item at the index:
	m_Data[idx] = item;

	// increase
	m_size++;
}

//////////////////////////////////////////////////////////////////////////
//	insertafter()
//	inserts the item after the index
template <typename T>
void CF::EGG::vect<T>::insertafter(unsigned int idx, const T& item)
{
	if (idx == 0)
	{
		pushfront(item);
	}

	ensure_capacity();

	// shift each element back one
	for (unsigned int i = m_size; i > idx+1; i--)
	{
		m_Data[i] = m_Data[i - 1];
	}

	// put the new item at the index:
	m_Data[idx+1] = item;

	// increase
	m_size++;
}

//////////////////////////////////////////////////////////////////////////
//	removeback()
//	
template <typename T>
T& CF::EGG::vect<T>::removeback()
{
	return remove(m_size-1);
}

//////////////////////////////////////////////////////////////////////////
//	removefront()
//	
template <typename T>
T& CF::EGG::vect<T>::removefront()
{
	return remove(0);
}

//////////////////////////////////////////////////////////////////////////
//	remove()
//	
template <typename T>
T& CF::EGG::vect<T>::remove(unsigned int idx)
{
	T* p = &(m_Data[idx]);
	T retval = T(m_Data[idx]);
	p->~T(); // invoke destructor

	unsigned int num_shifts = (m_size-1) - idx;
	for (unsigned int i = 0; i < num_shifts; i++)
	{
		m_Data[idx + i] = m_Data[idx + i + 1];
	}
	// decrease size
	m_size--;

	return retval;
}

//////////////////////////////////////////////////////////////////////////
//	remove_subset()
//	
//template <typename T>
//CF::EGG::vect<T>& CF::EGG::vect<T>::remove_subset(unsigned int idx_begin, unsigned int idx_end)
//{
//
//}


//////////////////////////////////////////////////////////////////////////
//	resize_capacity()
//	resizes the array so more elements can be pushed back into it.
//	kind of inefficient memory-wise because it writes the data to a new location in memory 
//	(doubling occupation in memory = capacity + new capacity (usu. capacity*2) = capacity *3 )
//	and has to delete the original one
template <typename T>
void CF::EGG::vect<T>::resize_capacity(unsigned int amt_bytes)
{
	// if m_Data is not null
	if (m_Data != nullptr)
	{
		//	point to data to copy back to m_Data later
		T *swap_ptr = m_Data;
		//	re-allocate m_Data
		m_Data = new T[amt_bytes/sizeof(T)];
		//	copy the temporary buffer to the new location of m_Data
		for (unsigned int i = 0; i < m_size; i++)
		{
			m_Data[i] = swap_ptr[i];
		}
		//	delete the original
		delete[] swap_ptr;
	}
	// otherwise, don't bother creating a temporary buffer. Just initialize
	else
	{
		m_Data = new T[amt_bytes/sizeof(T)];
	}

	//	set the capacity to the new size in memory reserved for it
	m_capacity = amt_bytes;
}

//////////////////////////////////////////////////////////////////////////
//	resize()
//	resizes the array, resizes the array so more elements can be pushed back into it.
//	does the same thing as resize_capacity, only it is resizing
//	based on the number of new elements provided it needs to accommodate
template <typename T>
void CF::EGG::vect<T>::resize(unsigned int num_elmts)
{
	resize_capacity(num_elmts * sizeof(T));
}

//////////////////////////////////////////////////////////////////////////
//					inlines

//////////////////////////////////////////////////////////////////////////
//	operator+
//	
template<typename T>
inline CF::EGG::vect<T> operator+(CF::EGG::vect<T> lhs, const CF::EGG::vect<T>& rhs)
{
	return lhs += rhs;
}