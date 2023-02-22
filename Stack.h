#ifndef __STACK_H__
#define __STACK_H__

namespace Stack
{
	const int STACK_CAPACITY = 4096;

	struct Stack
	{
		int count;
		int countR;
		char values[STACK_CAPACITY];
		float Numbers[STACK_CAPACITY];
	};
	
	Stack Create();
	bool Push(Stack& stack, char value);
	bool PushR(Stack& stack, float value);
	char Pop(Stack& stack);
	float PopR(Stack& stack);
	char Top(const Stack& stack);
	int Size(const Stack& stack);
	int Count(const Stack& stack);
	bool IsEmpty(const Stack& stack);
	void Clear(Stack& stack);
}

#endif