#include "BinaryTree.h"
#include "TreeNode.h"

BinaryTree::~BinaryTree() {
    delete root;
}

TreeNode* BinaryTree::Search(int value) const {
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
        BinaryTree::Insert(root, iValue);
    else
        root = new TreeNode(iValue);
}

void BinaryTree::Insert(TreeNode* root, int iValue) {
    if (root->GetValue() == 0)
        root = new TreeNode(iValue);
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
