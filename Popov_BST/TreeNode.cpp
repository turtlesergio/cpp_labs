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

void TreeNode::Insert(TreeNode* &root, int iValue) {
    if (root == nullptr) {
        root = new TreeNode(iValue);
        return;
    }
    if (root->GetValue() > iValue) {
        if (root->GetLeftChild() == nullptr)
            root->SetLeftChild(new TreeNode(iValue));
        else
            Insert(root->left, iValue);
    }
    else {
        if (root->GetRightChild() == nullptr)
            root->SetRightChild(new TreeNode(iValue));
        else
            Insert(root->right, iValue);
    }
}