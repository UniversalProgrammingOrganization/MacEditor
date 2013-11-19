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


int g_tests = 0;
int g_passd = 0;

#define LE_STRING (const char*)pLE->m_pObject

void report(
	const char* fnm,
	const char* got,
	const char* exp)
{
	g_tests++;

	if (got == exp)
	{
		g_passd++;

		std::cout << "PASS: "<< (fnm ? fnm : "NULL") << "() == " << (exp ? exp : "NULL") << ")\n";
	}
	else
	{
		std::cout << "FAIL: "<< (fnm ? fnm : "NULL") << "() == " << (got ? got : "NULL") << ")\n";
	}
}

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

	static const char enqueue[] = "Enqueue";

	ListElement* pLE = queue.Enqueue((OBJECT*)alpha);
	report(enqueue, LE_STRING, alpha);

	pLE = queue.Enqueue((OBJECT*)bravo);
	report(enqueue, LE_STRING, bravo);

	pLE = queue.Enqueue((OBJECT*)charlie);
	report(enqueue, LE_STRING, charlie);

	pLE = queue.Enqueue((OBJECT*)delta);
	report(enqueue, LE_STRING, delta);

	pLE = queue.Enqueue((OBJECT*)echo);
	report(enqueue, LE_STRING, echo);

	pLE = queue.Enqueue((OBJECT*)foxtrot);
	report(enqueue, LE_STRING, foxtrot);

	std::cout << "\n";
	
	std::cout << "Queue front: "<< (const char*)queue.getFront()->m_pObject << "\n";
	std::cout << "Queue back: "<< (const char*)queue.getBack()->m_pObject << "\n";

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
	
	std::cout << "Stack top: "<< (const char*)stack.getTop()->m_pObject << "\n";
	std::cout << "Stack bottom: "<< (const char*)stack.getBottom()->m_pObject << "\n";
	
	std::cout << "\n";
	
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	std::cout << "Pop: "<< (const char*)stack.Pop() << "\n";
	
	std::cout << "\n";
	
	std::cout << "Tests:  "<< g_tests << "\n";
	std::cout << "Passed: "<< g_passd << "\n";

	return 0;
}

