#include "vector"
#include "TreeNode.h"
#include "PlayField.h"
#include "string"
#include "iostream"

using namespace std;

void PrintField(PlayField field) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string output = "| ";
            if (field[PlayField::CellPos({ i, j })] == PlayField::csCross)
                output = "|X";
            if (field[PlayField::CellPos({ i, j })] == PlayField::csNought)
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
        node.addChild(new TreeNode(node.value().makeMove(emptyCells[i]), &node));
        BuildSubTree(node[i]);
    }
}

void CountResults(TreeNode& node, int(&results)[3]) {
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
    auto emptyCells = node.value().getEmptyCells();
    for (int i = 0; i < node.childCount(); i++) {
        CountResults(node[i], results);
    }
}

void WalkTree(TreeNode& node, PlayField playfield) {
    for (int i = 0; i < 9; i++) {
        PrintField(node[i].value());
        int results[3] = { 0, 0, 0 };
        CountResults(node[i], results);
        cout << "Xs: " << results[0] << "\tOs: " <<
             results[1] << "\tDraws: " << results[2] << "\n";
    }
}

int main() {
    PlayField playfield;
    TreeNode node(playfield);
    BuildSubTree(node);
    WalkTree(node, playfield);
    system("pause");
    return 0;
}
