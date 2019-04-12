// BinaryTreeInorderTraversal.cpp
// Created by Jeongjoon Lee on 4/12/2019

// Given a binary tree, return the inorder traversal of its nodes' values.
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
// Output: [1,3,2]

vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> result;
	inorderTraversal(root, result);
	return result;
}

void inorderTraversal(TreeNode* node, vector<int>& v)
{
	if (node == nullptr)
	{
		return;
	}
	
	inorderTraversal(node->left, v);
	v.push_back(node->val);
	inorderTraversal(node->right, v);
}