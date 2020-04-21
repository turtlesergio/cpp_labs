#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include "algorithm"

using namespace std;

class BinaryTree {
public:
	BinaryTree();
	BinaryTree(int value);
	~BinaryTree();
	
	void Insert(int value);
	TreeNode* Search(int value);
	//int NodesCount();
private:
	TreeNode* root;
	int height;

	void Insert(TreeNode* root, int iValue);
	TreeNode* Search(TreeNode* root, int value);
	
	//int nodesCountHelper(TreeNode* root);
	int heightHelper(TreeNode* root);
};

#endif
