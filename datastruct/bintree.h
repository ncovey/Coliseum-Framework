// binary tree

#pragma once

namespace CF
{
namespace EGG
{
	template <typename T>
	class bintree
	{
	public:
		bintree<T>();
		bintree<T>(const bintree<T>&)
		~bintree<T>();
		bintree<T>& operator=(const bintree<T>&);

		// getters
		unsigned int size() const;

		// TODO:

	private:
		// child node struct
		struct child
		{
			child<T>();
			T m_data;
			child<T> *m_left, *m_right;
		};
		// number of child elements in tree
		unsigned int m_size;
		// tree root
		child<T> *m_root;
	};

}

}