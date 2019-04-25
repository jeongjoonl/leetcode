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

int islandPerimeter(vector<vector<int>>& grid)
{
	
	int island = 0;
	int neighbor = 0;
	for (size_t i = 0; i < grid.size(); ++i)
	{
		for (size_t j = 0; j < grid[i].size(); ++j)
		{
			if (grid[i][j] == 1)
			{
				++island;
				
				if (j + 1 < grid[i].size() && grid[i][j + 1] == 1)
				{
					++neighbor;
				}
				
				if (i + 1 < grid.size() && grid[i + 1][j] == 1)
				{
					++neighbor;
				}
			}
		}
	}
	
	return island * 4 - neighbor * 2;
}