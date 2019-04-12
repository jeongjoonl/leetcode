// BinaryTreePreorderTraversal.cpp
// Created by Jeongjoon Lee on 4/12/2019

// Given a binary tree, return the preorder traversal of its nodes' values.
// 
// Example:
// 
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
// 
// Output: [1,2,3]

vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> result;
	preorderTraversal(root, result);
	return result;
}

void preorderTraversal(TreeNode* node, vector<int>& v)
{
	if (node == nullptr)
	{
		return;
	}
	
	v.push_back(node->val);
	preorderTraversal(node->left, v);
	preorderTraversal(node->right, v);
}