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

// A simple queue class.
// Uses in this program: parsing, tree traversal, recursion.

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
