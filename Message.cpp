#include <iostream>

#include "Message.h"
#include "Folder.h"

Message::Message(const Message& m):
	contents(m.contents), folders(m.folders)
{
	this->add_to_Folders(m);
}

Message& Message::operator=(const Message& rhs)
{
	// 通过先删除指针再插入它们来处理自赋值情况
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message& Message::operator=(Message&& rhs)
{
	if (this != &rhs) { // 直接检查自赋值情况
		this->remove_from_Folders();
		this->contents = std::move(rhs.contents);
		this->move_Folders(&rhs);
	}
	return *this;
}

Message::~Message()
{
	this->remove_from_Folders();
}

void Message::save(Folder&f)
{
	this->folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	this->folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

void Message::remove_from_Folders()
{
	for (auto f : this->folders) {
		f->remMsg(this);
	}
}

void Message::move_Folders(Message* m)
{
	folders = std::move(m->folders); // 使用set的移动赋值运算符
	for (auto f : this->folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	// 移动过后，m.folders仍有效，但不知道它包含什么内容，
	// 由于Message的析构函数遍历folders，我们希望确定set是空的
	m->folders.clear(); // 确保销毁m是无害的
}

void swap(Message& lhs, Message& rhs)
{
	using std::swap;

	for (auto f : lhs.folders) {
		f->remMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->remMsg(&rhs);
	}

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	for (auto f : lhs.folders) {
		f->addMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->addMsg(&rhs);
	}
}

std::ostream& operator<<(std::ostream& os, const Message& msg)
{
	os << "(" << &msg << ")MSG: " << std::endl
		<< "\t" << msg.contents << std::endl;
	os << "\tIN:" << std::endl;
	for (auto f : msg.folders) {
		os << "\t\t" << f << std::endl;
	}
	return os;
}
