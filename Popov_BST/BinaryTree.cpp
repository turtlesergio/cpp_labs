#include "stdafx.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::BinaryTree(int iValue) {
	root->SetValue(iValue);
}

BinaryTree::~BinaryTree() {
	delete (root->GetLeftChild());
	delete (root->GetRightChild());
}

TreeNode* BinaryTree::Search(int value) {
	return Search(root, value);
}

TreeNode* BinaryTree::Search(TreeNode* root, int iValue) {
	if (root == nullptr || root->GetValue() == iValue)
		return root;
	if (root->GetValue() < iValue)
		return BinaryTree::Search(root->GetRightChild(), iValue);
	return BinaryTree::Search(root->GetLeftChild(), iValue);
}

void BinaryTree::Insert(int iValue) {
	if (root != nullptr)
		this->Insert(root, iValue);
	else
		root = new TreeNode(iValue);
}

void BinaryTree::Insert(TreeNode* root, int iValue) {
	if (root->GetValue() > iValue) {
		if (root->GetLeftChild() != nullptr) 
			root->SetRightChild(new TreeNode(iValue));
		else 
			Insert(root->GetLeftChild(), iValue);
	}
	else {
		if (root->GetRightChild() != nullptr)
			root->SetRightChild(new TreeNode(iValue));
		else 
			Insert(root->GetRightChild(), iValue);
	}
}

//int BinaryTree::NodesCount() {
//	return nodesCountHelper(root);
//}

//
//int BinaryTree::nodesCountHelper(TreeNode* root) {
//	if (!root)
//		return 0;
//	else
//		return (1 +
//		nodesCountHelper(root->GetLeftChild()) +
//		nodesCountHelper(root->GetRightChild()));
//}
//
int BinaryTree::heightHelper(TreeNode* root) {
	if (root == nullptr)
		return 0;
	else return 1 + std::max(heightHelper(root->GetLeftChild()),
		heightHelper(root->GetRightChild()));
}
