// MinimumAbsoluteDifferenceInBST.cpp
// Created by Jeongjoon Lee on 4/14/2019.

// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
//
// Example:
//
// Input:
//
//    1
//     \
//      3
//     /
//    2
//
// Output:
// 1
//
// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

int getMinimumDifference(TreeNode* root)
{
	int result = INT_MAX;
	TreeNode* preNode = nullptr;
	inorderTraversal(root, preNode, result);
	
	return result;
}
	
void inorderTraversal(TreeNode* node, TreeNode*& preNode, int& result)
{
	if (node == nullptr)
	{
		return;
	}
	
	inorderTraversal(node->left, preNode, result);
	
	if (preNode != nullptr)
	{
		result = std::min(result, node->val - preNode->val);
	}
	preNode = node;
	
	inorderTraversal(node->right, preNode, result);
}