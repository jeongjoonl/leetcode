// MaxAreaOfIsland.cpp
// Created by Jeongjoon Lee on 4/24/2019

// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
//
// Example 1:
//
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
//
// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
//
// Example 2:
//
// [[0,0,0,0,0,0,0,0]]
//
// Given the above grid, return 0.
//
// Note: The length of each dimension in the given grid does not exceed 50.

int dfs(vector<vector<int>>& grid, const int& i, const int& j, const int& ROW_LENGTH, const int& COL_LENGTH)
{
	if (i < 0 || j < 0 || i >= ROW_LENGTH || j >= COL_LENGTH || grid[i][j] == 0)
	{
		return 0;
	}
	
	// Mark visited
	grid[i][j] = 0;
	
	return dfs(grid, i + 1, j, ROW_LENGTH, COL_LENGTH) +
		dfs(grid, i - 1, j, ROW_LENGTH, COL_LENGTH) +
		dfs(grid, i, j + 1, ROW_LENGTH, COL_LENGTH) +
		dfs(grid, i, j - 1, ROW_LENGTH, COL_LENGTH) + 1;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
	const int ROW_LENGTH = grid.size();
	const int COL_LENGTH = ROW_LENGTH > 0 ? grid[0].size() : 0;
	
	int maxArea = 0;
	
	for (size_t i = 0; i < ROW_LENGTH; ++i)
	{
		for (size_t j = 0; j < COL_LENGTH; ++j)
		{
			if (grid[i][j] == 1)
			{
				maxArea = std::max(maxArea, dfs(grid, i, j, ROW_LENGTH, COL_LENGTH));
			}
		}
	}
	
	return maxArea;
}