#ifndef NODE_H
#define NODE_H

class TreeNode {
public:
    TreeNode() : value(0) {};
    explicit TreeNode(int iValue) : value(iValue) {}
    ~TreeNode();

    int GetValue();
    TreeNode* GetLeftChild() const;
    TreeNode* GetRightChild() const;

    void SetLeftChild(TreeNode* node);
    void SetRightChild(TreeNode* node);
private:
    const int value = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

#endif // NOD{}E_H
