#pragma once
#include <string>
#include <algorithm>
class HasPtr
{
	friend void swap(HasPtr& lhs, HasPtr& rhs);
public:
	HasPtr(const std::string& s = std::string()):
		i(0), ps(new std::string(s)), use(new std::size_t(1)) {}
	HasPtr(const HasPtr& newPtr):
		i(newPtr.i), ps(newPtr.ps), use(newPtr.use) {
		++(*use);
	}
	~HasPtr();

	/*ָ�븳ֵ*/
	HasPtr& operator=(const HasPtr&);
private:
	int i;
	std::string* ps;
	std::size_t* use;
};

inline void swap(HasPtr& lhs, HasPtr& rhs) {
	using std::swap;
	swap(lhs.i, rhs.i);
	swap(lhs.ps, rhs.ps);
	swap(lhs.use, rhs.use);
}

