// COS30008, Problem Set 7, 2020

#pragma once

#include "List.h"
#include <stdexcept>

template<class T>
class Queue
{
private:
	List<T> fElements;

public:
	typedef typename List<T>::Iterator Iterator;
	bool isEmpty() const
	{
		return fElements.isEmpty();
	}

	int size() const
	{
		return fElements.size();
	}

	void enqueue(const T& aElement)
	{
		fElements.push_back(aElement);
	}

	void dequeue()
	{
		if (isEmpty())
			throw std::underflow_error("Queue empty.");

		fElements.remove(fElements[0]);
	}

	const T& top() const
	{
		if (isEmpty())
			throw std::underflow_error("Queue empty.");

		return fElements[0];
	}
	const T& operator[] (size_t aIndex) const
	{
		return fElements[aIndex];
	}
	Iterator begin() const
	{
		return fElements.begin();
	}
	Iterator end() const
	{
		return fElements.end();
	}
	Iterator rbegin() const
	{
		return --(end());
	}
	Iterator rend() const
	{
		return begin();
	}
};


