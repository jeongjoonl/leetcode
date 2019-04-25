// CountOfSmallerNumbersAfterSelf.cpp
// Created by Jeongjoon Lee on 4/24/2019.

// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.

void merge(vector<pair<int,int>>& nums, int low, int high, int mid, vector<int>& count)
{
	int i = low;
	int j = mid + 1;
	
	int k = 0;
	vector<pair<int, int>> temp(high - low + 1);
	
	while (i <= mid && j <= high)
	{
		if (nums[i].first <= nums[j].first)
		{
			count[nums[i].second] += (j - (mid + 1));
			temp[k] = nums[i];
			++i;
		}
		else
		{
			temp[k] = nums[j];
			++j;
		}

		++k;
	}
	
	while (i <= mid)
	{
		count[nums[i].second]  += (high - mid);
		temp[k] = nums[i];
		++i;
		++k;
	}
	
	while (j <= high)
	{
		temp[k] = nums[j];
		++j;
		++k;
	}
	
	k = 0;
	for (size_t i = low; i <= high; ++i, ++k)
	{
		nums[i] = temp[k];
	}
}

void mergeSort(vector<pair<int, int>>& nums, int low, int high, vector<int>& count)
{
	if (low < high)
	{
		int mid = (high + low) / 2;
		mergeSort(nums, low, mid, count);
		mergeSort(nums, mid + 1, high, count);
		
		merge(nums, low, high, mid, count);
	}
}

vector<int> countSmaller(vector<int>& nums)
{
	vector<int> result(nums.size(), 0);
	vector<pair<int, int>> indexedNums(nums.size());
	
	for (size_t i = 0; i < nums.size(); ++i)
	{
		indexedNums[i] = make_pair(nums[i], i);
	}
	
	mergeSort(indexedNums, 0, nums.size() - 1, result);
	
	return result;
}