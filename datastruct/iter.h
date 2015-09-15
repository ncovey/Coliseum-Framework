//////////////////////////////////////////////////////////////////////////
//	iterator class
//////////////////////////////////////////////////////////////////////////

#pragma once

namespace CF
{
namespace EGG
{

	
	/******************************************************************************/
	/*	Note: to implement in your container class create the following typedefs: */
	/*	
	/*	typedef __itr< T, my_node<T> > iter;
	/*	typedef __itr< T, my_node<T> const > const_iter
	/*
	/*	At the moment, I am not sure it is worth spending the time to implement other
	/*	types of iterators (reverse_iterator, const_reverse_iterator, input_iterator,
	/*	random_access_iterator, bidirectional_iterator, forward_iterator, etc.)
	/******************************************************************************/


	//////////////////////////////////////////////////////////////////////////
	//	iterator class:
	template< typename value_type >
	class __itr
	{
	public:
		__itr();
		~__itr();

		// copy ctor
		__itr(const __itr&);

		// assignment:
		virtual __itr& operator=(const __itr&);

		// comparison:
		virtual bool operator==(const __itr&) const;
		virtual bool operator!=(const __itr&) const;

		// increment
		virtual __itr& operator++();
		// decrement
		virtual __itr& operator--();

		virtual const value_type& operator*() const;
		virtual value_type& operator*() const;
		virtual const value_type* operator->() const;
		virtual value_type* operator->() const;

	protected:
		value_type *m_ptr;
		void swap(__itr& lhs, __itr& rhs);

	}; // end class iter

	//////////////////////////////////////////////////////////////////////////
	//	const iterator
	template< typename value_type >
	class __const_itr
	{
	public:
		__const_itr();
		__const_itr(const __const_itr&);
		__const_itr(const __itr&);
		~__const_itr();

		// assignment:
		virtual __const_itr& operator=(__const_itr&);

		// comparison:
		virtual bool operator==(__const_itr&) const;
		virtual bool operator!=(__const_itr&) const;

		// increment
		virtual __const_itr& operator++();
		// decrement
		virtual __const_itr& operator--();

		virtual const value_type& operator*() const;
		virtual const value_type* operator->() const;

	protected:
		value_type *m_ptr;
		void swap(__const_itr& lhs, __const_itr& rhs);
	};

} // end namespace EGG
} // end namespace CF