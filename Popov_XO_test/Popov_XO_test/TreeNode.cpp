#include "TreeNode.h"
#include "cassert"

TreeNode::TreeNode(PlayField newBoard, TreeNode* parent) : playboard(newBoard), parent(parent)
{
}

TreeNode::~TreeNode() {
    children.clear();
}

bool TreeNode::isTerminal() const {
    assert(playboard.checkFieldStatus() != PlayField::fsInvalid);
    return playboard.checkFieldStatus() != PlayField::fsNormal;
}

void TreeNode::addChild(TreeNode* child) {
    assert(children.size() <= child->childQty());
    child->parent = this;
    children.push_back(child);
}

TreeNode& TreeNode::operator[](const int index) const {
    return *children[index];
}

const PlayField& TreeNode::value() const {
    return playboard;
}

int TreeNode::childCount() const {
    return children.size();
}

int TreeNode::childQty() const {
    return (parent ? parent->childQty() - 1 : 9);
}
