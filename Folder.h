#pragma once
#include <set>
#include <string>
class Message;
class Folder
{
	friend void swap(Folder& lhs, Folder& rhs);
	friend std::ostream& operator<< (std::ostream& os, const Folder& folder);
public:
	Folder() = default;
	Folder(const Folder&);
	~Folder();
	Folder& operator=(const Folder&);

	void addMsg(Message* msg) { msgs.insert(msg); }
	void remMsg(Message* msg) { msgs.erase(msg); }
private:
	std::set<Message* > msgs;

	void deleteFolders();
	void addMsgs(const Folder&);
};

void swap(Folder& lhs, Folder& rhs);
std::ostream& operator<< (std::ostream& os, const Folder& folder);
