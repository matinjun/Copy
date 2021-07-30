#include <iostream>
#include "Folder.h"
#include "Message.h"

Folder::Folder(const Folder& rhs):msgs(rhs.msgs)
{
	addMsgs(rhs);
}

Folder::~Folder()
{
	deleteFolders();
}

Folder& Folder::operator=(const Folder& rhs)
{
	// 处理自身赋值
	this->deleteFolders();
	this->msgs = rhs.msgs;
	this->addMsgs(rhs);
	return *this;
}

void Folder::deleteFolders()
{
	for (auto pm : msgs) {
		pm->folders.erase(this);
	}
}

void Folder::addMsgs(const Folder& rhs)
{
	for (auto pm : rhs.msgs) {
		pm->folders.insert(this);
	}
}

void swap(Folder& lhs, Folder& rhs)
{
	using std::swap;
	lhs.deleteFolders();
	rhs.deleteFolders();

	lhs.msgs.swap(rhs.msgs);

	lhs.addMsgs(lhs);
	rhs.addMsgs(rhs);
}

std::ostream& operator<<(std::ostream& os, const Folder& folder)
{
	os << "(" << &folder << ")" << "Folder: " << std::endl;
	for (auto msg : folder.msgs) {
		os << "\t(" << msg << ") " << std::endl;
	}
	return os;
}
