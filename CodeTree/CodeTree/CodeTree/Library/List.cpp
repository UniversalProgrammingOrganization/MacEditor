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

#include "List.h"

ListElement::ListElement(OBJECT* pObject) // Element constructor
{
	m_pObject = pObject;
	m_pNext = NULL;
}

ListElement* List::getHead()
{
	return m_pHead;
}

ListElement* List::getTail()
{
	return m_pTail;
}

List::List() // List constructor
{
	m_pHead = NULL;
	m_pTail = NULL;
}

List::~List() // List destructor
{
	while (m_pHead) // while the Head element is not NULL,
	{
		RemoveHead(); // Remove elements
	}
}

ListElement* List::AddHead(OBJECT* pObject) // AddHead function
{
	if (!pObject) // if the object pointer is NULL,
	{
		return NULL; // do not Push
	}
	
	ListElement* pElement = new ListElement(pObject); // create a new element
	
	if (pElement) // if the element was allocated,
	{
		if (m_pHead) // if the Head element is not NULL,
		{
			pElement->m_pNext = m_pHead; // uptate the next pointer of the new element
		}
		
		m_pHead = pElement; // place the new element at the Head of the List
		
		if (!m_pTail) // if the Tail element is NULL,
		{
			m_pTail = m_pHead; // set the Tail element equal to the Head element
		}
	}
	
	return pElement; // return the new element pointer
}

ListElement* List::AddTail(OBJECT* pObject) // AddTail function
{
	if (!pObject) // if the object pointer is NULL,
	{
		return NULL; // do not add tail
	}
	
	ListElement* pElement = new ListElement(pObject); // create a new element
	
	if (pElement) // if the element was allocated,
	{
		if (m_pTail) // if the Tail element is not NULL,
		{
			m_pTail->m_pNext = pElement; // uptate the next pointer of the Tail element
		}
		
		m_pTail = pElement; // place the new element at the Tail of the List
		
		if (!m_pHead) // if the Head element is NULL,
		{
			m_pHead = m_pTail; // set the Head element equal to the Tail element
		}
	}
	
	return pElement; // return the new element pointer
}

OBJECT* List::RemoveHead() // RemoveHead function
{
	ListElement* pElement = m_pHead; // get the element at the Head of the List
	
	if (pElement) // if the element is not NULL,
	{
		m_pHead = m_pHead->m_pNext; // point the Head element at the next element
		
		if (!m_pHead) // if the Head element is NULL,
		{
			m_pTail = NULL; // set the Tail element to NULL
		}
		
		OBJECT* pObject = pElement->m_pObject; // get the object pointer from the element
		
		delete pElement; // delete the element
		
		return pObject; // return the object pointer
	}
	else // if the element is NULL,
	{
		return NULL; // return NULL, as the List is empty
	}
}
