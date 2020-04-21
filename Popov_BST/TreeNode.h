#ifndef NODE_H
#define NODE_H

class TreeNode {
public:
	TreeNode();
	TreeNode(int iValue);
	~TreeNode();

	int GetValue();
	TreeNode* GetLeftChild();
	TreeNode* GetRightChild();

	void SetValue(int iValue);
	void SetLeftChild(TreeNode* node);
	void SetRightChild(TreeNode* node);
private:
	int value;
	TreeNode* left;
	TreeNode* right;
};

#endif // NODE_H
