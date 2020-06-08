#include "BinaryTree.h"

BinaryTree::~BinaryTree() {
    delete m_root;
}

TreeNode* BinaryTree::Search(int value) const {
    return Search(m_root, value);
}

TreeNode* BinaryTree::Search(TreeNode* root, const int iValue) {
    if (root == nullptr || root->GetValue() == iValue)
        return root;
    if (root->GetValue() < iValue)
        return BinaryTree::Search(root->GetRightChild(), iValue);
    return BinaryTree::Search(root->GetLeftChild(), iValue);
}

void BinaryTree::Insert(int iValue) {
        TreeNode::Insert(m_root, iValue);
}


