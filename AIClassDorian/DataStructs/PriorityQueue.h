#pragma once
//Graph
#include "DataStructs/Graph/GraphStructs.h"

#include <vector>


//Flexible element for priority queue
template<typename PQTType>
class QueueElement
{
public:
	PQTType Element;
	float mPriority = -1;

	QueueElement(PQTType T);
	QueueElement(PQTType T, float Priority);	
};


template<typename PQTType>
QueueElement<PQTType>::QueueElement(PQTType T)
{
	Element = T;
	mPriority = -1;
}

template<typename PQTType>
QueueElement<PQTType>::QueueElement(PQTType T, float Priority)
{
	Element = T;
	mPriority = Priority;
}

//Required operator overload to use the std::sort method
template<typename PQTType>
inline bool operator<(const PQTType& left, const PQTType& right)
{
	return (left.mPriority < right.mPriority);
}

//Gotta have em both
template<typename PQTType>
inline bool operator>(const PQTType& left, const PQTType& right)
{
	return (right.mPriority < left.mPriority);
}


//The actual queue
template<typename PQTType>
struct PriorityQueue
{
public:
	void Push(const QueueElement<PQTType> NewElement);
	QueueElement<PQTType> Pop();


	const PriorityQueue Get() { return const Queue };

private:
	std::vector<QueueElement<PQTType>> Queue;
};

//Uses std sort with our overloaded <
template<typename PQTType>
void PriorityQueue<PQTType>::Push(QueueElement<PQTType> NewElement)
{
	Queue.push_back(NewElement);
	std::sort(Queue.begin(), Queue.end());
}

template<typename PQTType>
QueueElement<PQTType> PriorityQueue<PQTType>::Pop()
{
	QueueElement<PQTType> temp = Queue[0];
	Queue.pop_back();
	return(temp);
}

