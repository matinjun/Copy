#pragma once
#include <string>
class TreeNode
{
public:
	TreeNode(const std::string& val = std::string(),
		TreeNode* l = nullptr, TreeNode* r = nullptr) :
		value(val), left(l), right(r), count(0) {}
	~TreeNode();
	TreeNode(const TreeNode& node):
		value(node.value), count(node.count), 
		left(new TreeNode(*(node.left))), 
		right(new TreeNode(*(node.right))) {}
	TreeNode& operator=(const TreeNode& node);


	TreeNode& leftNode() { return *left; }
	TreeNode& rightNode() { return *right; }
	std::string getValue() const { return value; }
	int getCount() const { return count; }
	void setValue(const std::string& val) { value = val; }
	void setCount(int cnt) { count = cnt; }
private:
	std::string value;
	int count;
	TreeNode* left;
	TreeNode* right;
};

