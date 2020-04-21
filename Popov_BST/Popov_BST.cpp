#include "stdafx.h"
#include "TreeNode.h"
#include "BinaryTree.h"
#include "iostream"

using namespace std;

void CreateMinimalBST(int* iArray, int start, int end) {
	BinaryTree bst = BinaryTree();
	for (int i = start; i < end; i++) {
		bst.Insert(iArray[i]);
	}
}

int main()
{
	int array[30] = { 58, 72, 29, 37, 89, 53, 91, 5, 31, 62,
		18, 21, 28, 16, 10, 87, 12, 69, 65, 64,
		86, 63, 98, 60, 85, 100, 41, 57, 44, 34 };
	CreateMinimalBST(array, 0, 30);
	system("pause");
	return 0;
}

