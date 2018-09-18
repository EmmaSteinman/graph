#include <sstream>
#include <string>
#include <iostream>
#include <exception>


/*
* notes
* minimum method to return the minimum element, but the function header makes it return a pointer. it works but it's returning the address and not the int value of the smallest element
*/

/*--------------------------
* default constructor
* uses minHeap default constructor
--------------------------*/
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue():MinHeap<KeyType>()
{
}

/*--------------------------
* construct an empty MinPriorityQueue with capacity n
* uses minHeap constructor to construct an empty heap with capacity n
--------------------------*/
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(int n):MinHeap<KeyType>(n)
{
}
/*--------------------------
* copy constructor
* uses minHeap copy constructor
--------------------------*/
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(const MinPriorityQueue<KeyType>& pq):MinHeap<KeyType>(pq)
{

}

//===================================================================================================
/*--------------------------
* minimum()
* return smallest element in MinPriorityQueue
* parameters: void
* return value: KeyType*
* precondition: MPQ is not empty (exception to handle this case)
* postcondition: MPQ is unchanged
--------------------------*/
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::minimum( void ) const		//note: fix exceptions
{
	if (empty())
	{
		throw EmptyError();
	}
	else
	{
		return A[0];
	}
}

/*--------------------------
* extractMin()
* delete the minimum element of MinPriorityQueue and return it
* parameters: void
* return value: KeyType*
* precondition: non-empty MPQ (exception to handle this case)
* postcondition: MPQ no longer contains smallest value
--------------------------*/
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::extractMin( void )
{
	//cout << "EXTRACT MIN!!!!!!!!!!" << endl;
	if (empty())
	{
		throw EmptyError();
	}
	else
	{
		KeyType* temp = A[0];
		//cout << "temp 1: " <<*temp << endl;
		A[0] = A[heapSize - 1];
		//cout << "temp 2: " << *temp << endl;
		heapSize -= 1;
		//cout << "temp 3: " << *temp << endl;
		heapify(0);
		//cout << "temp 4: " << *temp << endl;
		//cout << "END EXTRACT MIN!!!!!!!!!!" << endl;
		return temp;
	}
}

/*--------------------------
* decreaseKey()
* decrease the value of an element
* paramters: int index of value to decrease priority of, KeyType* value to decrease
* return value: void
* precondition: non-empty MPQ (exception)
* postcondition: given value has decreased in priority and its position has changed
--------------------------*/
template <class KeyType>
void MinPriorityQueue<KeyType>::decreaseKey( int index, KeyType* key )
{
	if (empty())
	{
		throw EmptyError();
	}
	else
	{
		A[index] = key;
		while (index > 0 and *(A[parent(index)]) > *(A[index]))
		{
			swap(index, parent(index));
			index = parent(index);
		}

	}
}

/*--------------------------
* insert
* insert a new element
* parameters: KeyType* key to insert
* return value: void
* precondition: MPQ exists
* postcondition: MPQ now contains value passed to insert
--------------------------*/
template <class KeyType>
void MinPriorityQueue<KeyType>::insert( KeyType* key )
{
	if (heapSize + 1 == capacity - 1)
	{
		throw FullError();
	}
	else
	{
		A[heapSize] = key;
		heapSize++;
		decreaseKey(heapSize-1, key);
	}
}

/*--------------------------
* empty()
* return whether the MinPriorityQueue is empty
* parameters: void
* return value: bool
* precondition: MPQ exists
* postcondition: MPQ is unchanged
--------------------------*/
template <class KeyType>
bool MinPriorityQueue<KeyType>::empty( void ) const
{
	return heapSize == 0;
}

/*--------------------------
* length
* returns length of MinPriorityQueue
* parameters: void
* return value: int
* precondition: MPQ exists
* postcondition: unchanged MPQ
--------------------------*/
template <class KeyType>
int MinPriorityQueue<KeyType>::length( void ) const
{
	return heapSize;
}


/*--------------------------
* toString
* inserts MPQ contents into string
* parameters: none
* return value: string
--------------------------*/
template <class KeyType>
std::string MinPriorityQueue<KeyType>::toString() const
{
	std::stringstream ss;

	if (heapSize == 0)
	{
		ss << "[ ]";
	}
	else
	{
		ss << "[";
		for (int index = 0; index < heapSize - 1; index++)
			ss << *(A[index]) << ", ";
		ss << *(A[heapSize - 1]) << "]";
	}
	return ss.str();
}


/*-------------------------
* overloaded cout operator
--------------------------*/

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinPriorityQueue<KeyType>& pq)
{
	stream << pq.toString();
	return stream;
}


/*template <class KeyType>
int MinPriorityQueue<KeyType>::findIndex(KeyType * k)
{
	if (empty())
		throw EmptyError();

	else
	{
			for (int i = 0; i < length(); i++)
			{
				if (A[i] == *k)
					return i;
			}
			return -1;
	}
}
*/
