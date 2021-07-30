#pragma once
#include "TreeNode.h"
class BinStrTree
{
public:
	BinStrTree(TreeNode * rt = nullptr): root(rt) {}
	~BinStrTree();
	BinStrTree(const BinStrTree& tree);
	BinStrTree& operator=(const BinStrTree& tree);
private:
	TreeNode* root;
};

