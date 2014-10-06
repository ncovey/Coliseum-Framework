//////////////////////////////////////////////////////////////////////////
//	pr_queue.h
//////////////////////////////////////////////////////////////////////////

#pragma once

namespace CF
{
namespace EGG
{
	//////////////////////////////////////////////////////////////////////////
	//	priority queue
	//		a priority queue is basically a singly-linked list where each element is
	//		assigned a certain level of priority upon insertion
	template<typename T>
	class pr_queue
	{
	public:
		enum QUEUE_PRIORITY
		{
			  NONE			= -1
			, LOWEST		= 0
			, LOW			= 1
			, BELOW_NORMAL	= 2
			, NORMAL		= 3
			, ABOVE_NORMAL	= 4
			, HIGH			= 5
			, HIGHEST		= 6
		};

		//////////////////////////////////////////////////////////////////////////
		//	ctor/dtor
		pr_queue<T>();
		pr_queue<T>(const pr_queue<T>& prq);
		~pr_queue<T>();

		//////////////////////////////////////////////////////////////////////////
		//	operators
		pr_queue<T>& operator=(const pr_queue<T>& prq);

		const T& operator[](unsigned int idx) const;
		T& operator[](unsigned int idx);

		//////////////////////////////////////////////////////////////////////////
		//	manipulators

		// add to queue
		void enqueue(const T& item, QUEUE_PRIORITY pr = LOWEST);
		// remove front of queue
		T& pop();
		
		// look at the front
		T& front() const;


	private:

		//////////////////////////////////////////////////////////////////////////
		//	queue slot
		//
		struct qslot
		{
			QUEUE_PRIORITY m_priority;
			T *m_Data;
			qslot() : m_Data(new T()), m_priority(NONE) {}

			QUEUE_PRIORITY& operator++(void) { return (m_priority < HIGHEST) ? m_priority += 1 : HIGHEST; }
			QUEUE_PRIORITY& operator--(void) { return (m_priority > LOWEST) ? m_priority -= 1 : LOWEST; }

		};

		//////////////////////////////////////////////////////////////////////////
		//

		EGG::list_d<qslot> m_queue;


		//////////////////////////////////////////////////////////////////////////
		//	comparison operator overloads for convenience
		inline bool operator==(const qslot& lhs, const qslot& rhs) { return lhs.m_priority == rhs.m_priority; }
		inline bool operator<=(const qslot& lhs, const qslot& rhs) { return lhs.m_priority <= rhs.m_priority; }
		inline bool operator>=(const qslot& lhs, const qslot& rhs) { return lhs.m_priority >= rhs.m_priority; }
		inline bool operator<(const qslot& lhs, const qslot& rhs)  { return lhs.m_priority < rhs.m_priority; }
		inline bool operator>(const qslot& lhs, const qslot& rhs)  { return lhs.m_priority > rhs.m_priority; }
	};

}

}