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

// A simple stack class.
// Uses in this program: parsing, tree traversal, recursion.

#ifndef __CodeTree__Stack__
#define __CodeTree__Stack__

#include "library.h"

class StackElement // represents a stack Element
{
public:
	OBJECT* m_pObject; // pointer to an Object
	StackElement* m_pNext; // pointer to the Next element
	
	StackElement(OBJECT* pObject); // Element constructor
};

class Stack // represents a Stack
{
public:
	StackElement* m_pTop; // pointer to the top element
	StackElement* m_pBottom; // pointer to the Back element
	
	Stack(); // Stack constructor
	
	~Stack(); // Stack destructor
	
	StackElement* Push(OBJECT* pObject); // Push function
	
	OBJECT* Pop(); // Pop function
};

#endif /* defined(__CodeTree__Stack__) */
