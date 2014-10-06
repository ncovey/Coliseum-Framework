// binary tree

#pragma once

namespace CF
{
namespace EGG
{
	template <typename T>
	class bi_tree
	{
	public:
		bi_tree<T>();
		bi_tree<T>(const bi_tree<T>&)
		~bi_tree<T>();
		bi_tree<T>& operator=(const bi_tree<T>&);

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