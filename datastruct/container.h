//////////////////////////////////////////////////////////////////////////
// virtual class all EGG container class must implement:
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "iter.h"

namespace CF
{
namespace EGG
{
	//////////////////////////////////////////////////////////////////////////
	//	Declaration:

	template<typename T>
	class container
	{
	protected:

		template<typename T>
		class __node
		{
			T m_data;
		};

	public:

		//////////////////////////////////////////////////////////////////////////
		//	iterator class:
		//template< typename value_type, typename node_type >
		class iter
		{
		public:
			iter();
			~iter();

			// copy ctor
			iter(const iter&);

			// assignment:
			iter& operator=(const iter&);

			// comparison:
			bool operator==(const iter&) const;
			bool operator!=(const iter&) const;

			// increment
			iter& operator++();
			// decrement
			iter& operator--();

			const T& operator*() const;
			T& operator*() const;
			const T* operator->() const;
			T* operator->() const;

		private:
			T *m_ptr;
			void swap(iter& lhs, iter& rhs);
			
		}; // end class iter

		//////////////////////////////////////////////////////////////////////////
		//	const iterator
		class const_iter
		{
		public:
			const_iter();
			const_iter(const const_iter&);
			const_iter(const iter&);
			~const_iter();

			// assignment:
			const_iter& operator=(const_iter&);

			// comparison:
			bool operator==(const_iter&) const;
			bool operator!=(const_iter&) const;

			// increment
			const_iter& operator++();
			// decrement
			const_iter& operator--();

			const T& operator*() const;
			const T* operator->() const;

		private:
			T *m_ptr;
			void swap(const_iter& lhs, const_iter& rhs);
		};

	public:
		//container<T>();
		//~container<T>();

		//container<T>(const container<T>& copy);

		//////////////////////////////////////////////////////////////////////////
		//	Operator Overloads:
		
		// access
		virtual T&					operator[](const uint32 idx);
		virtual const T&			operator[](const uint32 idx) const;

		// assignment
		virtual container<T>&		operator=(const container<T>&);
		virtual bool				operator==(const container<T>&);
		virtual bool				operator!=(const container<T>&);
		// appends the new element at the end
		virtual const T&			operator+=(const T&);
		virtual T&					operator+=(T&&);
		// concatenates another container at the end of this one
		virtual const container<T>&	operator+=(const container<T>&);
		virtual container<T>&		operator+=(container<T>&&);

		//////////////////////////////////////////////////////////////////////////
		//	Methods:

		//	access:
		virtual T&			at(const index_t);
		virtual const T&	at(const index_t) const;
		
		virtual T&			front();
		virtual const T&	front() const;
		virtual T&			back();
		virtual const T&	back() const;

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

		// requests the container to condense its size.
		virtual void		shrink_to_fit();

		// getters:
		virtual sz_t		size() const;
		//virtual sz_t		max_size() const;
		virtual bool		empty() const;	// in keeping with the standard

		// returns an iter to the first instance, otherwise returns ::end()
		virtual iter		find(const T&);
		// returns an iter to the first instance, otherwise returns ::end()
		virtual const_iter	find(const T&) const;

		//////////////////////////////////////////////////////////////////////////
		//	Iterator Implementation:

		virtual iter		begin();
		virtual const_iter	begin() const;
		virtual iter		end();
		virtual const_iter	end() const;

		// inserts new elements before the specified position
		virtual void		insert(const_iter& position, const T& value);
		virtual void		insert(const_iter& position, T&& value);
		// inserts num_items before the position, initialized to value
		virtual void		insert(const_iter& position, uint32 num_items, const T& value);
		
		virtual void		insert(index_t index, const T& value);
		virtual void		insert(index_t index, T&& value);
		virtual void		insert(index_t index, uint32 num_items, const T& value);

		virtual void		erase(const_iter&);
		virtual void		erase(const_iter& begin_at, const_iter& end_at);

		virtual void		erase(const index_t);
		virtual void		erase(const index_t begin_at, const index_t end_at);

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

		void				swap(const container<T>&);

		protected:
			friend class iter;
			friend class const_iter;
	};

	template <typename T>
	void swap(container<T>& lhs, container<T>& rhs);
}
}
