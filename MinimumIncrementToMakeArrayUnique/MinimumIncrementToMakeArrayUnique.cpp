// MinimumIncrementToMakeArrayUnique.cpp
// Created by Jeongjoon Lee on 3/3/2019.

//Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.
//
//Return the least number of moves to make every value in A unique.
//
//
//Example 1:
//
//Input: [1,2,2]
//Output: 1
//Explanation:  After 1 move, the array could be [1, 2, 3].
//
//Example 2:
//
//Input: [3,2,1,2,1,7]
//Output: 6
//Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
//It can be shown with 5 or less moves that it is impossible for the array to have all unique values.

int minIncrementForUnique(vector<int>& A)
{
	int moves = 0;

	set<int> seen; 
	
	for (const auto& VALUE : A)
	{
		if (seen.find(VALUE) == seen.end())
		{
			seen.insert(VALUE);
		}
		else
		{
			int incVal = VALUE;
			do
			{
				++incVal;
				++moves;
				
			} while (seen.find(incVal) != seen.end());
			
			seen.insert(incVal);
		}
	}
	
	return moves;
}