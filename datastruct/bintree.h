// binary tree

#pragma once

#include "__tree.h"

namespace CF
{
namespace EGG
{
	template <typename T>
	class bintree
	{

	public:
		bintree<T>();
		bintree<T>(const bintree<T>&);
		~bintree<T>();
		bintree<T>& operator=(const bintree<T>&);

		// getters
		unsigned int size() const;

		// TODO:

	private:
		// child node struct

		T* m_pData;
		__tree<T> *m_root;
		// number of child elements in tree
		unsigned int m_size;

	};	// class bintree

};	//	namespace CF
};	//	namespace EGG

