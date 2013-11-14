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

// tests for library classes/code.


#include <iostream>
#include "../../Library/Queue.h"
#include "../../Library/Stack.h"

int main(int argc, const char * argv[])
{
	std::cout << "Testing Queue:\n\n";
	
	Queue queue;
	
	static const char alpha[]   = "ALPHA";
	static const char bravo[]   = "BRAVO";
	static const char charlie[] = "CHARLIE";
	static const char delta[]   = "DELTA";
	static const char echo[]    = "ECHO";
	static const char foxtrot[] = "FOXTROT";
	
	std::cout << "Enqueue("<< (const char*)alpha << ")\n";
	queue.Enqueue((OBJECT*)alpha);
	std::cout << "Enqueue("<< (const char*)bravo << ")\n";
	queue.Enqueue((OBJECT*)bravo);
	std::cout << "Enqueue("<< (const char*)charlie << ")\n";
	queue.Enqueue((OBJECT*)charlie);
	std::cout << "Enqueue("<< (const char*)delta << ")\n";
	queue.Enqueue((OBJECT*)delta);
	std::cout << "Enqueue("<< (const char*)echo << ")\n";
	queue.Enqueue((OBJECT*)echo);
	std::cout << "Enqueue("<< (const char*)foxtrot << ")\n";
	queue.Enqueue((OBJECT*)foxtrot);
	
	std::cout << "\n";
	
	std::cout << "Queue front: "<< (const char*)queue.m_pFront->m_pObject << "\n";
	std::cout << "Queue back: "<< (const char*)queue.m_pBack->m_pObject << "\n";

	std::cout << "\n";
	
	std::cout << "Dequeue: "<< (const char*)queue.Dequeue() << "\n";
	std::cout << "Dequeue: "<< (const char*)queue.Dequeue() << "\n";
	std::cout << "Dequeue: "<< (const char*)queue.Dequeue() << "\n";
	std::cout << "Dequeue: "<< (const char*)queue.Dequeue() << "\n";
	std::cout << "Dequeue: "<< (const char*)queue.Dequeue() << "\n";
	std::cout << "Dequeue: "<< (const char*)queue.Dequeue() << "\n";

	std::cout << "\n";
	std::cout << "\n";
	
	std::cout << "Testing Stack:\n\n";
	
	Stack stack;
	
	std::cout << "Push("<< (const char*)alpha << ")\n";
	stack.Push((OBJECT*)alpha);
	std::cout << "Push("<< (const char*)bravo << ")\n";
	stack.Push((OBJECT*)bravo);
	std::cout << "Push("<< (const char*)charlie << ")\n";
	stack.Push((OBJECT*)charlie);
	std::cout << "Push("<< (const char*)delta << ")\n";
	stack.Push((OBJECT*)delta);
	std::cout << "Push("<< (const char*)echo << ")\n";
	stack.Push((OBJECT*)echo);
	std::cout << "Push("<< (const char*)foxtrot << ")\n";
	stack.Push((OBJECT*)foxtrot);
	
	std::cout << "\n";
	
	std::cout << "Stack top: "<< (const char*)stack.m_pTop->m_pObject << "\n";
	std::cout << "Stack bottom: "<< (const char*)stack.m_pBottom->m_pObject << "\n";
	
	std::cout << "\n";
	
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	
	std::cout << "\n";
	
	return 0;
}

