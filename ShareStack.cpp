#include "ShareStack.h"

bool ShareStack::push(int i, elemtp data)
{
	if (top[0] + 1 == top[1]) return false;
	if (0 == i) {
		stack[++top[0]] = data;
	}
	else {
		stack[--top[1]] = data;
	}
	return true;
}

bool ShareStack::pop(int i, elemtp& data)
{
	if (0 == i) {
		if (-1 == top[0]) {
			return false;
		}
		data = stack[top[0]--];
	}
	else {
		if (this->maxsize + 0 == top[1]) return false;
		data = stack[top[1]++];
	}
	return true;
}
