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

// A circular queue class, restricted to sizes that are a power of 2.
// Uses in this program: real-time parsing, high-performance buffering.

#ifndef __CodeTree__CircularQueue__
#define __CodeTree__CircularQueue__

#include "library.h"

class CircularQueue
{
	public:
		uint32_t m_nEnqueues;  // total number of enqueue operations
		uint32_t m_nDequeues;  // total number of dequeue operations
		uint32_t m_nIndexMask; // Index Mask - a bitmask
		OBJECT** m_ppObjects;  // pointer to array of object pointers

		CircularQueue();

		~CircularQueue();

		void Reset();

		bool Init(uint32_t dwSize);

		OBJECT* Enqueue(OBJECT* pObject);

		OBJECT* Dequeue();

		OBJECT* Peek();

		uint32_t Size();
};

#endif /* defined(__CodeTree__CircularQueue__) */
