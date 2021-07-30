#pragma once
#include <string>
#include <set>
class Folder;
class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);
	friend std::ostream& operator<<(std::ostream& os, const Message& msg);
public:
	explicit Message(const std::string &str= std::string()):
		contents(str) {}

	Message(const Message&);
	// 由于set的insert可能产生bad_alloc异常，此处不适用noexcept
	// 移动拷贝构造函数
	Message(Message&& rhs) :
		contents(std::move(rhs.contents)) {
		move_Folders(&rhs);
	}
	Message& operator=(const Message&);
	// 移动赋值
	Message& operator=(Message&& rhs);
	~Message();

	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;

	// 将本Message添加到指向m的Folder中
	void add_to_Folders(const Message&);
	void remove_from_Folders();

	// 从本Message移动Folder指针
	void move_Folders(Message* m);
};

void swap(Message&, Message&);
std::ostream& operator<<(std::ostream& os, const Message& msg);
