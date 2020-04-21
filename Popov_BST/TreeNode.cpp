#include "stdafx.h"
#include "TreeNode.h"

TreeNode::TreeNode() {
	value = 0;
	left = nullptr;
	right = nullptr;
}

TreeNode::TreeNode(int iValue) {
	value = iValue;
	left = nullptr;
	right = nullptr;
}

TreeNode::~TreeNode() {
	if (this != nullptr) {
		delete this;
		delete left;
		delete right;
	}
}

int TreeNode::GetValue() {
	if (this != nullptr)
		return value;
	return 0;
}

TreeNode* TreeNode::GetLeftChild() {
	if (this != nullptr && this->left != nullptr)
		return this->left;
	return nullptr;
}

TreeNode* TreeNode::GetRightChild() {
	if (this != nullptr && this->right != nullptr)
		return this->right;
	return nullptr;
}

void TreeNode::SetValue(int iValue) {
	this->value = iValue;
}

void TreeNode::SetLeftChild(TreeNode* node) {
	this->left = node;
}

void TreeNode::SetRightChild(TreeNode* node) {
	this->right = node;
}
