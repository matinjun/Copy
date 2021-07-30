#pragma once
#include <vector>
typedef char elemtp;
class ShareStack
{
public:
	ShareStack():stack(100), maxsize(100) {
		top[0] = -1;
		top[1] = 100;
	}
	ShareStack(int size) :maxsize(size), stack(size) {
		top[0] = -1;
		top[1] = size;
	}
	bool push(int i, elemtp data);
	bool pop(int i, elemtp& data);
private:
	int maxsize;
	std::vector<elemtp> stack;
	int top[2];
};

