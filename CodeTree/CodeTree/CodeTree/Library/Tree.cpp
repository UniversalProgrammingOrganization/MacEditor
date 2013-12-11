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

#include "Tree.h"

TreeBranch::TreeBranch(OBJECT* pObject) : m_Branches()
{
	m_pObject = pObject;
}

TreeBranch::~TreeBranch()
{
	while (getBranchCount())
	{
		TreeBranch* pBranch = (TreeBranch*)m_Branches.RemoveHead();
		
		if (pBranch)
		{
			delete pBranch;
		}
	}
}

// adds a branch to the tail of the branch list:
TreeBranch* TreeBranch::AddBranch(OBJECT* pObject)
{
	TreeBranch* pBranch = new TreeBranch(pObject); // create a new branch
	
	ListElement* pElement = m_Branches.AddTail(pBranch);
	
	return (pElement) ? (TreeBranch*)pElement->m_pObject : NULL;
}

// removes the head branch and returns its object pointer:
OBJECT* TreeBranch::RemoveBranch()
{
	return m_Branches.RemoveHead();
}

// get pointer to next branch:
ListElement* TreeBranch::getNextBranch(ListElement* pElement)
{
	return pElement->getNext();
}

// get count of child branches:
uint32_t TreeBranch::getBranchCount()
{
	return m_Branches.getCount();
}

TreeBranch* Tree::getTrunk()
{
	return m_pTrunk;
}

Tree::Tree(OBJECT* pObject)
{
	m_pTrunk = new TreeBranch(pObject);
}

Tree::~Tree()
{
	m_pTrunk->~TreeBranch();
}


