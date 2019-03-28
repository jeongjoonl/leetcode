// BinaryTreeMaximumPathSum.cpp
// Created by Jeongjoon Lee on 3/27/2019.

// Given a non-empty binary tree, find the maximum path sum.
//
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
// Example 1:
//
// Input: [1,2,3]
//
//        1
//       / \
//      2   3
//
// Output: 6
//
// Example 2:
//
// Input: [-10,9,20,null,null,15,7]
//
//    -10
//    / \
//   9  20
//     /  \
//    15   7
//
// Output: 42

int maxPathSum(TreeNode* root)
{
	int result = INT_MIN;
	maxPathSum(root, result);
	
	return result;
}

int maxPathSum(TreeNode* node, int& maxSum) {
	
	// Base case
	if (node == nullptr)
	{
		return 0;
	}
	
	int leftSum = maxPathSum(node->left, maxSum);
	int rightSum = maxPathSum(node->right, maxSum);
	
	int totalNodeSum = node->val + leftSum + rightSum;
	
	int maxPathSum = std::max(node->val, std::max(node->val + leftSum, node->val + rightSum));
	
	maxSum = std::max(maxSum,std::max(maxPathSum, totalNodeSum));
	
	return maxPathSum;
}