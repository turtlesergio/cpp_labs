#include "TreeNode.h"

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

int TreeNode::GetValue() const {
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

void TreeNode::Insert(TreeNode* &root, int iValue) {
    if (root == nullptr) {
        root = new TreeNode(iValue);
        return;
    }
    ( root->GetValue() > iValue ) ? Insert(root->left, iValue) :
                                    Insert(root->right, iValue);
}