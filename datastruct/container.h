//////////////////////////////////////////////////////////////////////////
// virtual class all EGG container class must implement:
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "types.h"
#include "iter.h"

namespace CF
{
namespace EGG
{
	//////////////////////////////////////////////////////////////////////////
	//	Declaration:

	template < typename T >
	class container
	{
	protected:

		typedef __const_itr	< T >	const_iter;
		typedef __itr < T >			iter;

	public:

		//container<T>();
		//~container<T>();

		//container<T>(const container<T>& copy);

		//////////////////////////////////////////////////////////////////////////
		//	Operator Overloads:
		
		// access
		virtual const T&			operator[](const uint32 idx) const;
		virtual T&					operator[](const uint32 idx);

		// assignment
		//virtual container_type&		operator=(const container_type&)
		//virtual bool				operator==(const container<T>&);
		//virtual bool				operator!=(const container<T>&);
		// appends the new element at the end
		//virtual const T&			operator+=(const T&);
		//virtual T&					operator+=(T&&);
		//// concatenates another container at the end of this one
		//virtual const container<T>&	operator+=(const container<T>&);
		//virtual container<T>&		operator+=(container<T>&&);

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

	};

	//template <typename T>
	//void swap(container<T>& lhs, container<T>& rhs);
}
}
