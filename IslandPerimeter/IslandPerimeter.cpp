// IslandPerimeter.cpp
// Created by Jeongjoon Lee on 4/24/2019

// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
//
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
//
// The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
//
// Example:
//
// Input:
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]
//
// Output: 16

int dfs(vector<vector<int>>& grid, const int& i, const int& j, const int& m, const int& n)
{
	if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
	{
		return 1;
	}
	
	if (grid[i][j] < 0)
	{
		return 0;
	}
	
	// Mark visited
	grid[i][j] = -grid[i][j];
	
	return dfs(grid, i + 1, j, m, n) + // Down
		dfs(grid, i - 1, j, m, n) +    // Up
		dfs(grid, i, j + 1, m, n) +    // Right
		dfs(grid, i, j - 1, m, n);     // Left
}

int islandPerimeter(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = (m > 0) ? grid[0].size() : 0;
	
	
	int i;
	int j;
	
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (grid[i][j] == 1)
			{
				goto stop;
			}
		}
	}
	stop:
	
	return dfs(grid, i, j, m, n);
}