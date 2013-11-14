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

#include "Stack.h"

StackElement::StackElement(OBJECT* pObject) // Element constructor
{
	m_pObject = pObject;
	m_pNext = NULL;
}

Stack::Stack() // Stack constructor
{
	m_pTop = NULL;
	m_pBottom = NULL;
}

Stack::~Stack() // Stack destructor
{
	while (m_pTop) // while the bottom element is not NULL,
	{
		Pop(); // Pop elements
	}
}

StackElement* Stack::Push(OBJECT* pObject) // Push function
{
	if (!pObject) // if the object pointer is NULL,
	{
		return NULL; // do not Push
	}
	
	StackElement* pElement = new StackElement(pObject); // create a new element
	
	if (pElement) // if the element was allocated,
	{
		if (m_pTop) // if the top element is not NULL,
		{
			pElement->m_pNext = m_pTop; // uptate the next pointer of the new element
		}
		
		m_pTop = pElement; // place the new element at the top of the stack
		
		if (!m_pBottom) // if the bottom element is NULL,
		{
			m_pBottom = m_pTop; // set the bottom element equal to the top element
		}
	}
	
	return pElement; // return the new element pointer
}

OBJECT* Stack::Pop() // Pop function
{
	StackElement* pElement = m_pTop; // get the element at the bottom of the stack
	
	if (pElement) // if the element is not NULL,
	{
		m_pTop = m_pTop->m_pNext; // point the bottom element at the next element
		
		if (!m_pTop) // if the top element is NULL,
		{
			m_pBottom = NULL; // set the bottom element to NULL
		}
		
		OBJECT* pObject = pElement->m_pObject; // get the object pointer from the element
		
		delete pElement; // delete the element
		
		return pObject; // return the object pointer
	}
	else // if the element is NULL,
	{
		return NULL; // return NULL, as the stack is empty
	}
}
