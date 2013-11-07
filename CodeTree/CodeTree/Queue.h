//
//  Queue.h
//  CodeTree
//
//  Created by daniel on 11/6/13.
//
// A simple queue class.
// uses in this program: parsing, tree traversal, recursion.

#ifndef __CodeTree__Queue__
#define __CodeTree__Queue__

#include "library.h"

class QueueElement // represents a queue Element
{
public:
	OBJECT* m_pObject; // pointer to an Object
	QueueElement* m_pNext; // pointer to the Next element
	
	QueueElement(OBJECT* pObject); // Element constructor
};

class Queue // represents a Queue
{
public:
	QueueElement* m_pFront; // pointer to the Front element
	QueueElement* m_pBack; // pointer to the Back element
	
	Queue(); // Queue constructor

	~Queue(); // Queue destructor

	QueueElement* Enqueue(OBJECT* pObject); // Enqueue function

	OBJECT* Dequeue(); // Dequeue function
};

#endif /* defined(__CodeTree__Queue__) */
