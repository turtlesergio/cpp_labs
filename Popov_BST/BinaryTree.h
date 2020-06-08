#ifndef BST_H
#define BST_H

#include "TreeNode.h"

class BinaryTree {
public:
    BinaryTree() = default;
    explicit BinaryTree(const int iValue) : m_root(new TreeNode(iValue)) {}
    ~BinaryTree();

    void Insert(const int value);
    TreeNode* Search(const int value) const;
private:
    TreeNode* m_root = nullptr;
    static TreeNode* Search(TreeNode* const root, const int value);

};

#endif // BST_H
