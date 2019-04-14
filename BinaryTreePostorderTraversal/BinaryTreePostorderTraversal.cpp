// BinaryTreePostorderTraversal.cpp
// Created by Jeongjoon Lee on 4/12/2019.

// Given a binary tree, return the postorder traversal of its nodes' values.
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
// Output: [3,2,1]

vector<int> postorderTraversal(TreeNode* root)
{
	vector<int> result;
	postorderTraversal(root, result);
	return result;
}

void postorderTraversal(TreeNode* node, vector<int>& v)
{
	if (node == nullptr)
	{
		return;
	}
	
	postorderTraversal(node->left, v);
	postorderTraversal(node->right, v);
	v.push_back(node->val);
}