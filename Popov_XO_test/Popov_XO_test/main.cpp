#include <vector>
#include "TreeNode.h"
#include <string>
#include <iostream>

using namespace std;

void PrintField(const PlayField &field) {
    for (int i = 0; i < PlayField::m_size; i++) {
        for (int j = 0; j < PlayField::m_size; j++) {
            string output = "| ";
            if (field[{i, j}] == PlayField::csCross)
                output = "|X";
            if (field[{i, j}] == PlayField::csNought)
                output = "|O";
            cout << output;
        }
        cout << "|\n";
    }
    cout << "\t";
}

void BuildSubTree(TreeNode& node) {
    if (node.isTerminal())
        return;
    const auto emptyCells = node.value().getEmptyCells();
    for (int i = 0; i < emptyCells.size(); i++) {
        node.addChild(new TreeNode(node.value().makeMove(emptyCells[i])), &node);
        BuildSubTree(node[i]);
    }
}

void CountResults(TreeNode& node, int(&results)[PlayField::m_size]) {
    if (node.isTerminal()) {
        switch (node.value().checkFieldStatus()) {
            case PlayField::fsCrossesWin:
                results[0]++;
                break;
            case PlayField::fsNoughtsWin:
                results[1]++;
                break;
            case PlayField::fsDraw:
                results[2]++;
                break;
        }
        return;
    }
    for (int i = 0; i < node.childCount(); i++) {
        CountResults(node[i], results);
    }
}

void WalkTree(TreeNode& node) {
    for (int i = 0; i < PlayField::m_size * PlayField::m_size; i++) {
        PrintField(node[i].value());
        int results[PlayField::m_size] = { 0, 0, 0 };
        CountResults(node[i], results);
        cout << "Xs: " << results[0] << "\tOs: " <<
             results[1] << "\tDraws: " << results[2] << "\n";
    }
}

int main() {
    PlayField playfield;
    TreeNode node(playfield);
    BuildSubTree(node);
    WalkTree(node);
    return 0;
}
