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

// reports on an OBJECT test:
void report(
	const char* fnm,
	OBJECT* got,
	const char* exp)
{
	g_tests++;

	const char* cGot = (const char*)got;
	const char* cExp = (const char*)exp;
	
	if (got == exp)
	{
		g_passd++;

		std::cout << "PASS: "<< (fnm ? fnm : "NULL") << " == " << (cExp ? cExp : "NULL") << "\n";
	}
	else
	{
		std::cout << "FAIL: "<< (fnm ? fnm : "NULL") << " == " << (cGot ? cGot : "NULL") << "\n";
	}
}

// reports on a list element test:
void reportLE(
  const char* fnm,
  ListElement* pLE,
	const char* exp)
{
	if (exp)
	{
		report(fnm, pLE->m_pObject, exp);
	}
	else
	{
		report(fnm, NULL, exp);
	}
}


int main(int argc, const char * argv[])
{
	static const char alpha[]   = "ALPHA";
	static const char bravo[]   = "BRAVO";
	static const char charlie[] = "CHARLIE";
	static const char delta[]   = "DELTA";
	static const char echo[]    = "ECHO";
	static const char foxtrot[] = "FOXTROT";

	std::cout << "Testing Queue:\n\n";
	
	static const char enqueue[] = "Enqueue()";
	static const char dequeue[] = "Dequeue()";
	static const char getfront[] = "getFront()";
	static const char getback[] = "getBack()";
	
	Queue queue;
	
	std::cout << "queue should be empty:\n";
	
	report(dequeue, queue.Dequeue(), NULL);
	reportLE(getfront, queue.getFront(), NULL);
	reportLE(getback, queue.getBack(), NULL);
	
	std::cout << "enqueue some items:\n";
	
	reportLE(enqueue, queue.Enqueue((OBJECT*)alpha),   alpha);
	reportLE(enqueue, queue.Enqueue((OBJECT*)bravo),   bravo);
	reportLE(enqueue, queue.Enqueue((OBJECT*)charlie), charlie);
	reportLE(enqueue, queue.Enqueue((OBJECT*)delta),   delta);
	reportLE(enqueue, queue.Enqueue((OBJECT*)echo),    echo);
	reportLE(enqueue, queue.Enqueue((OBJECT*)foxtrot), foxtrot);

	std::cout << "queue should have content:\n";
	
	reportLE(getfront, queue.getFront(), alpha);
	reportLE(getback, queue.getBack(), foxtrot);
	
	std::cout << "dequeue all items:\n";
	
	report(dequeue, queue.Dequeue(), alpha);
	report(dequeue, queue.Dequeue(), bravo);
	report(dequeue, queue.Dequeue(), charlie);
	report(dequeue, queue.Dequeue(), delta);
	report(dequeue, queue.Dequeue(), echo);
	report(dequeue, queue.Dequeue(), foxtrot);
	
	std::cout << "stack should be empty (again):\n";
	
	report(dequeue, queue.Dequeue(), NULL);
	reportLE(getfront, queue.getFront(), NULL);
	reportLE(getback, queue.getBack(), NULL);

	std::cout << "\n";
	std::cout << "\n";
	
	std::cout << "Testing Stack:\n\n";
	
	Stack stack;
	
	static const char f_push[] = "Push()";
	static const char f_pop[] = "Pop()";
	static const char gettop[] = "getTop()";
	static const char getbottom[] = "getBottom()";
	
	std::cout << "stack should be empty:\n";
	
	report(f_pop, stack.Pop(), NULL);
	reportLE(gettop, stack.getTop(), NULL);
	reportLE(getbottom, stack.getBottom(), NULL);
	
	std::cout << "push some items:\n";
	
	reportLE(f_push, stack.Push((OBJECT*)alpha),   alpha);
	reportLE(f_push, stack.Push((OBJECT*)bravo),   bravo);
	reportLE(f_push, stack.Push((OBJECT*)charlie), charlie);
	reportLE(f_push, stack.Push((OBJECT*)delta),   delta);
	reportLE(f_push, stack.Push((OBJECT*)echo),    echo);
	reportLE(f_push, stack.Push((OBJECT*)foxtrot), foxtrot);
	
	std::cout << "stack should have content:\n";
	
	reportLE(gettop, stack.getTop(), foxtrot);
	reportLE(getbottom, stack.getBottom(), alpha);

	std::cout << "dequeue all items:\n";
	
	report(f_pop, stack.Pop(), foxtrot);
	report(f_pop, stack.Pop(), echo);
	report(f_pop, stack.Pop(), delta);
	report(f_pop, stack.Pop(), charlie);
	report(f_pop, stack.Pop(), bravo);
	report(f_pop, stack.Pop(), alpha);
	
	std::cout << "stack should be empty (again):\n";
	
	report(f_pop, stack.Pop(), NULL);
	reportLE(gettop, stack.getTop(), NULL);
	reportLE(getbottom, stack.getBottom(), NULL);
	
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "Tests:  "<< g_tests << "\n";
	std::cout << "Passed: "<< g_passd << "\n\n";
	
	return 0;
}

