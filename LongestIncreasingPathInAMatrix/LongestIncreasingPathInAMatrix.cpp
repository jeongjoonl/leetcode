// LongestIncreasingPathInAMatrix.cpp
// Created by Jeongjoon Lee on 4/23/2019.

// Given an integer matrix, find the length of the longest increasing path.
//
// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
//
// Example 1:
//
// Input: nums = 
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:
//
// Input: nums = 
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

int getVal(const vector<vector<int>>& matrix, const int& i, const int& j, const int& n, const int& m) {
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return -1;
    }
    
    return matrix[i][j];
}

int dfs(vector<vector<int>>& matrix, vector<vector<int>>& maxPath, const int& i, const int& j, const int& n, const int& m)
{
    int currentVal = matrix[i][j];
    
    int upVal = getVal(matrix, i - 1, j, n, m);
    int downVal = getVal(matrix, i + 1, j, n, m);
    int leftVal = getVal(matrix, i, j - 1, n, m);
    int rightVal = getVal(matrix, i, j + 1, n, m);
    
    int path = 0;
    
    // up
    if (upVal > currentVal)
    {
        if (maxPath[i - 1][j] < 1)
        {
            path = std::max(path, dfs(matrix, maxPath, i - 1, j, n, m));
        } 
        else
        {
            path = std::max(path, maxPath[i - 1][j]);
        }
    }
    
    
    // down
    if (downVal > currentVal)
    {
        if (maxPath[i + 1][j] < 1)
        {
            path = std::max(path, dfs(matrix, maxPath, i + 1, j, n, m));
        }
        else
        {
            path = std::max(path, maxPath[i + 1][j]);
        }
    }
    
    // left
    if (leftVal > currentVal)
    {
        if (maxPath[i][j - 1] < 1)
        {
            path = std::max(path, dfs(matrix, maxPath, i, j - 1, n, m));
        }
        else
        {
            path = std::max(path, maxPath[i][j - 1]);
        }
    }
    
    // right
    if (rightVal > currentVal)
    {
        if (maxPath[i][j + 1] < 1)
        {
            path = std::max(path, dfs(matrix, maxPath, i, j + 1, n, m));
        }
        else
        {
            path = std::max(path, maxPath[i][j + 1]);
        }
    }
    
    maxPath[i][j] = path + 1;
    
    return maxPath[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix)
{
    int n = 0;
    int m = 0;
    
    n = matrix.size();
    
    if (n > 0)
    {
        m = matrix[0].size();
    }
    
    int result = 0;
    vector<vector<int>> maxPath(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            result = std::max(result, dfs(matrix, maxPath, i, j, n, m));
        }
    }
    
    return result;
}
