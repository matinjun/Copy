#include "HasPtr.h"

HasPtr::~HasPtr()
{
	/*�ݼ�����������ü���*/
	if (--(*use) == 0) {
		/*���û�������û����ͷű��������ĳ�Ա*/
		delete ps;
		delete use;
	}
}

HasPtr& HasPtr::operator=(const HasPtr& hasPtr)
{
#if 0
	/*ֵ����*/
	/*�ȿ�������ʱ����ȥ�����ͷ����������ٽ���ʱ�������������*/
	auto np = new std::string(*hasPtr.ps);
	
	delete this->ps;

	this->ps = np;
	i = hasPtr.i;
	return *this;
#endif
	/*ָ�뿽��*/
	/*�����Ҳ������������ü���*/
	++(*hasPtr.use);
	/*�ݼ�����������ü���*/
	if (--(*this->use) == 0) {
		/*���û�������û����ͷű��������ĳ�Ա*/
		delete this->use;
		delete this->ps;
	}
	/*���ݿ���*/
	this->i = hasPtr.i;
	this->ps = hasPtr.ps;
	this->use = hasPtr.use;

	/*���ر�����*/
	return *this;
}
