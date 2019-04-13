// MinimumDistanceBetweenBSTNodes.cpp
// Created by Jeongjoon Lee on 4/13/201

// Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.
//
// Example :
//
// Input: root = [4,2,6,1,3,null,null]
// Output: 1
// Explanation:
// Note that root is a TreeNode object, not an array.
//
// The given tree [4,2,6,1,3,null,null] is represented by the following diagram:
//
//           4
//         /   \
//       2      6
//      / \    
//     1   3  
//
// while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
//
// Note:
//
//     1. The size of the BST will be between 2 and 100.
//     2. The BST is always valid, each node's value is an integer, and each node's value is different.

int minDiffInBST(TreeNode* root)
{
	std::vector<int> v;
	inorderTraversal(root, v);
	
	int minDiff = v[1] - v[0];
	for (int i = 1; i < v.size() - 1; ++i)
	{
		minDiff = std::min(minDiff, v[i + 1] - v[i]);
	}

	
	return minDiff;
}

void inorderTraversal(TreeNode* node, std::vector<int>& v)
{
	if (node == nullptr)
	{
		return;
	}
	
	inorderTraversal(node->left, v);
	v.push_back(node->val);
	inorderTraversal(node->right, v);
}