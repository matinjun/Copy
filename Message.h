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
	// ����set��insert���ܲ���bad_alloc�쳣���˴�������noexcept
	// �ƶ��������캯��
	Message(Message&& rhs) :
		contents(std::move(rhs.contents)) {
		move_Folders(&rhs);
	}
	Message& operator=(const Message&);
	// �ƶ���ֵ
	Message& operator=(Message&& rhs);
	~Message();

	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;

	// ����Message��ӵ�ָ��m��Folder��
	void add_to_Folders(const Message&);
	void remove_from_Folders();

	// �ӱ�Message�ƶ�Folderָ��
	void move_Folders(Message* m);
};

void swap(Message&, Message&);
std::ostream& operator<<(std::ostream& os, const Message& msg);
