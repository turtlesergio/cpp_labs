#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include "algorithm"

using namespace std;

class BinaryTree {
public:
    BinaryTree() : root() {};
    explicit BinaryTree(const int iValue) : root(new TreeNode(iValue)) {}
    ~BinaryTree();

    void Insert(int value);
    TreeNode* Search(int value) const;
private:
    TreeNode* root;

    static void Insert(TreeNode* root, int iValue);
    static TreeNode* Search(TreeNode* root, int value);
};

#endif
