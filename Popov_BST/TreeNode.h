#ifndef NODE_H
#define NODE_H

class TreeNode {
public:
    TreeNode() = delete;
    explicit TreeNode(const int iValue) : value(iValue) {}
    ~TreeNode();

    int GetValue() const;
    TreeNode* GetLeftChild() const;
    TreeNode* GetRightChild() const;

    void SetLeftChild(TreeNode* node);
    void SetRightChild(TreeNode* node);

    static void Insert(TreeNode* &root, int iValue);
private:
    const int value = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

#endif // NODE_H
