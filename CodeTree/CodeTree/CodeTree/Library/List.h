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

// A simple list class.
// Uses in this program: parsing, editing, core of Stack and Queue classes.

#ifndef __CodeTree__List__
#define __CodeTree__List__

#include "library.h"

class ListElement // represents a List Element
{
	public:
		OBJECT* m_pObject; // pointer to an Object
		ListElement* m_pNext; // pointer to the Next element
		
		ListElement(OBJECT* pObject); // Element constructor
};

class List // represents a List
{
	private:
		uint32_t m_nCount;
		ListElement* m_pHead; // pointer to the Head element
		ListElement* m_pTail; // pointer to the Tail element

	public:
		uint32_t getCount(); // get count of elements
		
		ListElement* getHead(); // get pointer to the Head element
	
		ListElement* getTail();  // get pointer to the Tail element

		List(); // List constructor
		
		~List(); // List destructor
		
		ListElement* AddHead(OBJECT* pObject); // AddHead function
		
		ListElement* AddTail(OBJECT* pObject); // AddTail function
		
		OBJECT* RemoveHead(); // RemoveHead function
};

#endif /* defined(__CodeTree__List__) */
