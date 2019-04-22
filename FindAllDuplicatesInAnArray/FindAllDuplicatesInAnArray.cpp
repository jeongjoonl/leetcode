// FindAllDuplicatesInAnArray.cpp
// Created by Jeongjoon Lee on 4/22/2019.

// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//
// Find all the elements that appear twice in this array.
//
// Could you do it without extra space and in O(n) runtime?
//
// Example:
//
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [2,3]

vector<int> findDuplicates(vector<int>& nums)
{
    vector<int> result;
    
    for (auto& num : nums)
    {
        int i = std::abs(num);
        
        if (nums[i - 1] < 0)
        {
            result.push_back(i);
        }
        
        nums[i - 1] = -nums[i - 1];
        
    }
    
    return result;
}
