#include "BinStrTree.h"

BinStrTree::~BinStrTree()
{
	if (root) {
		delete root;
		root = nullptr;
	}
}

BinStrTree::BinStrTree(const BinStrTree& tree):
	root(new TreeNode(*tree.root)) { }

BinStrTree& BinStrTree::operator=(const BinStrTree& tree)
{
	auto rt = new TreeNode(*tree.root);
	delete this->root;
	this->root = rt;
	return *this;
}
