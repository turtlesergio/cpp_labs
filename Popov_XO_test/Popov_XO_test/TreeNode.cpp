#include "stdafx.h"
#include "TreeNode.h"

TreeNode::TreeNode(PlayField newBoard, TreeNode* parent) : playboard(newBoard), parent(parent)
{
}

bool TreeNode::isTerminal() const {
	assert(playboard.checkFieldStatus() != PlayField::fsInvalid);
	return playboard.checkFieldStatus() == PlayField::fsNoughtsWin ||
		playboard.checkFieldStatus() == PlayField::fsCrossesWin ||
		playboard.checkFieldStatus() == PlayField::fsDraw;
}

void TreeNode::addChild(TreeNode* child) {
	assert(children.size() < 10);
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
