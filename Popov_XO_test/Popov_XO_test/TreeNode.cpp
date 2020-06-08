#include "TreeNode.h"
#include <cassert>

TreeNode::~TreeNode() {
    for (auto child : children)
        delete child;
}

bool TreeNode::isTerminal() const {
    auto fieldStatus = playboard.checkFieldStatus();
    assert(fieldStatus != PlayField::fsInvalid);
    return fieldStatus == PlayField::fsNoughtsWin ||
            fieldStatus == PlayField::fsCrossesWin ||
            fieldStatus == PlayField::fsDraw;
}

void TreeNode::addChild(TreeNode* child) {
    assert(children.size() < childQty());
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
    return (parent ? parent->childQty() - 1 : PlayField::m_size * PlayField::m_size);
}
