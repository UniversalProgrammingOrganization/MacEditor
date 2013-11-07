/*
CodeTree - A whitespace-agnostic, context-oriented code editor
Copyright (C) 2013  Daniel Randall

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Queue.h"

QueueElement::QueueElement(OBJECT* pObject) // Element constructor
{
	m_pObject = pObject;
	m_pNext = NULL;
}

Queue::Queue() // Queue constructor
{
	m_pFront = NULL;
	m_pBack = NULL;
}

Queue::~Queue() // Queue destructor
{
	while (m_pFront) // while the front element is not NULL,
	{
		Dequeue(); // dequeue elements
	}
}

QueueElement* Queue::Enqueue(OBJECT* pObject) // Enqueue function
{
	if (!pObject) // if the object pointer is NULL,
	{
		return NULL; // do not enqueue
	}
	
	QueueElement* pElement = new QueueElement(pObject); // create a new element
	
	if (pElement) // if the element was allocated,
	{
		if (m_pBack) // if the back element is not NULL,
		{
			m_pBack->m_pNext = pElement; // uptate the next pointer of the back element
		}
		
		m_pBack = pElement; // place the new element at the back of the queue
		
		if (!m_pFront) // if the front element is NULL,
		{
			m_pFront = m_pBack; // set the front element equal to the back element
		}
	}
	
	return pElement; // return the new element pointer
}

OBJECT* Queue::Dequeue() // Dequeue function
{
	QueueElement* pElement = m_pFront; // get the element at the front of the queue
	
	if (pElement) // if the element is not NULL,
	{
		m_pFront = m_pFront->m_pNext; // point the front element at the next element
		
		if (!m_pFront) // if the front element is NULL,
		{
			m_pBack = NULL; // set the back element to NULL
		}
		
		OBJECT* pObject = pElement->m_pObject; // get the object pointer from the element
		
		delete pElement; // delete the element
		
		return pObject; // return the object pointer
	}
	else // if the element is NULL,
	{
		return NULL; // return NULL, as the queue is empty
	}
}
