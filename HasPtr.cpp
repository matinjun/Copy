#include "HasPtr.h"

HasPtr::~HasPtr()
{
	/*递减本对象的引用计数*/
	if (--(*use) == 0) {
		/*如果没有其它用户，释放本对象分配的成员*/
		delete ps;
		delete use;
	}
}

HasPtr& HasPtr::operator=(const HasPtr& hasPtr)
{
#if 0
	/*值拷贝*/
	/*先拷贝到临时变量去，再释放左侧变量，再将临时变量拷贝到左侧*/
	auto np = new std::string(*hasPtr.ps);
	
	delete this->ps;

	this->ps = np;
	i = hasPtr.i;
	return *this;
#endif
	/*指针拷贝*/
	/*递增右侧运算对象的引用记数*/
	++(*hasPtr.use);
	/*递减本对象的引用计数*/
	if (--(*this->use) == 0) {
		/*如果没有其它用户，释放本对象分配的成员*/
		delete this->use;
		delete this->ps;
	}
	/*数据拷贝*/
	this->i = hasPtr.i;
	this->ps = hasPtr.ps;
	this->use = hasPtr.use;

	/*返回本对象*/
	return *this;
}
