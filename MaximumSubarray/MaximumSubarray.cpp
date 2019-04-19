// MaximumSubarray.cpp
// Created by Jeongjoon Lee on 4/19/2019.

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
// Example:
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
//     Output: 6
//     Explanation: [4,-1,2,1] has the largest sum = 6.
//     Follow up:
//
//     If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
int maxSubArray(vector<int>& nums)
{
	int accumMax = nums[0];
	int result = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		accumMax = std::max(accumMax + nums[i], nums[i]);
		result = std::max(accumMax, result);
	}
	
	return result;
}
