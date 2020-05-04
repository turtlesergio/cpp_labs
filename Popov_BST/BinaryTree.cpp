#include "BinaryTree.h"

BinaryTree::~BinaryTree() {
    delete m_root;
}

TreeNode* BinaryTree::Search(int value) const {
    return Search(m_root, value);
}

TreeNode* BinaryTree::Search(TreeNode* root, int iValue) {
    if (root == nullptr || root->GetValue() == iValue)
        return root;
    if (root->GetValue() < iValue)
        return BinaryTree::Search(root->GetRightChild(), iValue);
    return BinaryTree::Search(root->GetLeftChild(), iValue);
}

void BinaryTree::Insert(int iValue) {
    if (m_root != nullptr)
        BinaryTree::Insert(m_root, iValue);
    else
        m_root = new TreeNode(iValue);
}

void BinaryTree::Insert(TreeNode* root, int iValue) {
    if (root->GetValue() > iValue) {
        if (root->GetLeftChild() == nullptr)
            root->SetLeftChild(new TreeNode(iValue));
        else
            Insert(root->GetLeftChild(), iValue);
    }
    else {
        if (root->GetRightChild() == nullptr)
            root->SetRightChild(new TreeNode(iValue));
        else
            Insert(root->GetRightChild(), iValue);
    }
}
