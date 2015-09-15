//	underlying tree structure

#pragma once

///=======================================================================
//	Declaration:
///=======================================================================

namespace CF
{
namespace EGG
{	
	template < typename T >
	class __tree
	{

	public:

		__tree<T>(sz_t nChildren);
		__tree<T>(const __tree<T>&);
		~__tree<T>();
		
		virtual							__tree<T>& operator=(const __tree<T>&);

		virtual const __tree<T>&		operator[](uint32 idx) const;
		virtual __tree<T>&				operator[](uint32 idx);

		virtual	sz_t					size() const;

		const T&						get() const;
		const T&						set(const T&);

		const __tree<T>&				appendChild(const T&);
		void							removeChild(uint32 idx);

	private:

		uint32							num_elmts;
		T*								m_pData;
		vector<__tree<T>*>				m_vpChildren;

	};	//	class __tree

};	// namespace EGG
};	// namespace CF

///=======================================================================
//	Implementation:
///=======================================================================

template < typename T >
CF::EGG::__tree<T>::__tree(sz_t nChildren)
	:	num_elmts		(nChildren)
	,	m_pData			(nullptr)
	,	m_vpChildren	()
{
	for (uint32 i = 0; i < num_elmts; i++)
		m_vpChildren.push_back(nullptr);
}

template < typename T >
CF::EGG::__tree<T>::__tree(const __tree<T>& other_tree)
	: num_elmts(nChildren)
	, m_pData(nullptr)
	, m_vpChildren()
{

}

template < typename T >
CF::EGG::__tree<T>::~__tree()
{
	for (uint32 i = 0; i < num_elmts; i++)
}

template < typename T >
__tree<T>& 
CF::EGG::__tree<T>::operator=(const __tree<T>&)
{

}

template < typename T >
const __tree<T>& 
CF::EGG::__tree<T>::operator[](uint32 idx) const
{

}

template < typename T >
__tree<T>& 
CF::EGG::__tree<T>::operator[](uint32 idx)
{

}

template < typename T >
sz_t 
CF::EGG::__tree<T>::size() const
{

}