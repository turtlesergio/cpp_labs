#include "BinaryTree.h"
#include "iostream"
#include "cassert"

using namespace std;

void FindElement(BinaryTree* iTree, int iValue) {
    if (iTree->Search(iValue) != nullptr)
        cout << "The element \"" << iValue << "\" has been found!\n";
    else cout << "There's no element \"" << iValue << "\" in the tree :(\n";
}

void CreateMinimalBST(int* iArray, int start, int end) {
    auto bst = BinaryTree();
    for (int i = start; i < end; i++)
        bst.Insert(iArray[i]);
    FindElement(&bst, 100);
    FindElement(&bst, 0);
}

int main() {
    int array[30] = { 58, 72, 29, 37, 89, 53, 91, 5, 31, 62,
                      18, 21, 28, 16, 10, 87, 12, 69, 65, 64,
                      86, 63, 98, 60, 85, 100, 41, 57, 44, 34 };
    CreateMinimalBST(array, 0, 30);
    return 0;
}
