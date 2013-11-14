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

#include "CircularQueue.h"


CircularQueue::CircularQueue()
{
	m_ppObjects = NULL;
}

CircularQueue::~CircularQueue()
{
	Reset();
}

void CircularQueue::Reset()
{
	// free array of object pointers:
	if (m_ppObjects)
	{
		delete [] m_ppObjects;
	}

	m_nEnqueues = 0;
	m_nDequeues = 0;
	m_nIndexMask = 0;
	m_ppObjects = NULL;
}

bool CircularQueue::Init(uint32_t dwSize)
{
	// allow object re-use:
	Reset();

	// verify size is not zero:
	if (dwSize == 0)
	{
		return false;
	}

	// calculate the bit mask:
	m_nIndexMask = dwSize - 1;

	// verify size is a power of 2:
	if (dwSize & (m_nIndexMask))
	{
		return false;
	}

	// allocate the queue object pointers:
	m_ppObjects = new OBJECT*[dwSize];

	// will return true only if all of the above succeeded:
	return (m_ppObjects != NULL);
}

// enqueue function:
OBJECT* CircularQueue::Enqueue(OBJECT* pObject)
{
	// check for overflow:
	if (Size() > m_nIndexMask)
	{
		return NULL;
	}

	// calculate the enqueue index:
	uint32_t nEnqueueIndex = (m_nEnqueues & m_nIndexMask);

	// set the object pointer value:
	*(m_ppObjects + nEnqueueIndex) = pObject;

	// increment enqueue count:
	m_nEnqueues++;

	return pObject;
}

// dequeue function:
OBJECT* CircularQueue::Dequeue()
{
	// get the object pointer value:
	OBJECT* pObject = Peek();

	// increment dequeue count (if no peek error):
	if (pObject != NULL)
	{
		m_nDequeues++;
	}

	return pObject;
}

OBJECT* CircularQueue::Peek()
{
	// check for underflow:
	if (Size() == 0)
	{
		return NULL;
	}

	// calculate the dequeue index:
	uint32_t nDequeueIndex = (m_nDequeues & m_nIndexMask);

	// return the object pointer value:
	return *(m_ppObjects + nDequeueIndex);
}

// returns the distance between m_nDequeues and m_nEnqueues
// (the size of the actual queue contents):
uint32_t CircularQueue::Size()
{
	if (m_nDequeues < m_nEnqueues)
	{
		return (m_nEnqueues - m_nDequeues);
	}
	else
	{
		return (m_nDequeues - m_nEnqueues);
	}
}
