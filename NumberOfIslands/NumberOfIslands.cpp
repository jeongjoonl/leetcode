// NumberOfIsland.cpp
// Created by Jeongjoon Lee on 4/25/2019.

// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//
// Example 2:
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3

void dfs(vector<vector<char>>& grid, const int& i, const int& j, const int& ROW_LENGTH, const int& COL_LENGTH)
{
	if (i < 0 || j < 0 || i >= ROW_LENGTH || j >= COL_LENGTH || grid[i][j] == '0')
	{
		return;
	}
	
	// Mark Visited
	grid[i][j] = '0';
	
	dfs(grid, i + 1, j, ROW_LENGTH, COL_LENGTH);
	dfs(grid, i - 1, j, ROW_LENGTH, COL_LENGTH);
	dfs(grid, i, j + 1, ROW_LENGTH, COL_LENGTH);
	dfs(grid, i, j - 1, ROW_LENGTH, COL_LENGTH);
	
	
}

int numIslands(vector<vector<char>>& grid)
{
	int count = 0;
	
	for (size_t i = 0; i < grid.size(); ++i)
	{
		for(size_t j = 0; j < grid[i].size(); ++j)
		{
			if (grid[i][j] == '1')
			{
				++count;
				dfs(grid, i, j, grid.size(), grid[i].size());
			}
		}
	}
	
	return count;
}