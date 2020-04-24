#include "TreeNode.h"

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

int TreeNode::GetValue() {
    return value;
}

TreeNode* TreeNode::GetLeftChild() const {
    return left;
}

TreeNode* TreeNode::GetRightChild() const {
    return right;
}

void TreeNode::SetLeftChild(TreeNode* node) {
    left = node;
}

void TreeNode::SetRightChild(TreeNode* node) {
    right = node;
}
