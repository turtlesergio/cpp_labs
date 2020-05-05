#include "PlayField.h"
#include "vector"

class TreeNode {
public:
    TreeNode(PlayField newBoard, TreeNode* parent)
    : playboard(newBoard), parent(parent) {};
    ~TreeNode();
    bool isTerminal() const;
    void addChild(TreeNode* child);
    TreeNode& operator[](int index) const;
    int childCount() const;
    const PlayField& value() const;
private:
    int childQty() const;
    const PlayField playboard;
    std::vector<TreeNode*> children;
    const TreeNode* parent = nullptr;
};
