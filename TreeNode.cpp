#include "TreeNode.h"

TreeNode::~TreeNode()
{
	if (this->left) {
		delete left;
		left = nullptr;
	}
	if (this->right) {
		delete this->right;
		this->right = nullptr;
	}
}

TreeNode& TreeNode::operator=(const TreeNode& node)
{
	auto l = new TreeNode(*node.left);
	auto r = new TreeNode(*node.right);
	
	delete this->left;
	delete this->right;

	this->value = node.value;
	this->count = node.count;
	this->left = l;
	this->right = r;

	return *this;
}

