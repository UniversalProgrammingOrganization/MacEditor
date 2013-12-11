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

/*
 NOTE: These classes have not been tested/debugged (yet).
 
 This tree class uses a single-linked list object to keep track of the children
 of each branch, so child list modifications occur only at the ends 
 (additions to the tail and removals from the head).
  
 A variant of this class is forthcoming, where the child list objects 
 are double-linked and can be added/removed internally.
 */

#ifndef __Library__Tree__
#define __Library__Tree__

#include "List.h"

class TreeBranch // represents a Tree Branch
{
	private:
		List m_Branches;

	public:
		OBJECT* m_pObject;

		TreeBranch(OBJECT* pObject);
		
		~TreeBranch();
		
		// adds a branch to the tail of the branch list:
		TreeBranch* AddBranch(OBJECT* pObject);
		
		// removes the head branch and returns its object pointer:
		OBJECT* RemoveBranch();
		
		// get pointer to next branch:
		ListElement* getNextBranch(ListElement* pElement);

		// get count of child branches:
		uint32_t getBranchCount();
		
		// utility for accessing the branch object in a list element:
		static TreeBranch* asBranch(ListElement* pElement);
};

inline TreeBranch* TreeBranch::asBranch(ListElement* pElement)
{
	return (pElement) ? (TreeBranch*)pElement->m_pObject : NULL;
}

class Tree // represents a Tree
{
	private:
		TreeBranch* m_pTrunk;
		
	public:
		TreeBranch* getTrunk();
		
		Tree(OBJECT* pObject);
		
		~Tree();
};


#endif /* defined(__Library__Tree__) */
