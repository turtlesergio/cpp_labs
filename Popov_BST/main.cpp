#include "BinaryTree.h"
#include <iostream>
#include "cassert"
#include <algorithm>

using namespace std;

void FindElement(BinaryTree& iTree, int iValue) {
    if (iTree.Search(iValue) != nullptr)
        cout << "The element \"" << iValue << "\" has been found!\n";
    else cout << "There's no element \"" << iValue << "\" in the tree :(\n";
}

TreeNode* CreateMinimalBST(int* iArray, int start, int end) {
    if (start > end)
        return nullptr;
    const int mid = (start + end) / 2;
    auto tree = new TreeNode(iArray[mid]);
    tree->SetLeftChild(CreateMinimalBST(iArray, start, mid - 1));
    tree->SetRightChild(CreateMinimalBST(iArray, mid + 1, end));
    return tree;
}

int main() {
    static constexpr int arrSize = 30;
    int array[arrSize] = { 58, 72, 29, 37, 89, 53, 91, 5, 31, 62,
                      18, 21, 28, 16, 10, 87, 12, 69, 65, 64,
                      86, 63, 98, 60, 85, 100, 41, 57, 44, 34 };
    BinaryTree myTree;
    for (int i : array)
        myTree.Insert(i);
    FindElement(myTree, 100);
    FindElement(myTree, 0);
    sort(array, array + arrSize);
    auto bstTree = CreateMinimalBST(array, 0, arrSize);
    delete bstTree;
    return 0;
}
