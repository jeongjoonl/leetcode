// RemoveInvalidParentheses.cpp
// Created by Jeongjoon Lee on 3/28/2019

// Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
// 
// Note: The input string may contain letters other than the parentheses ( and ).
// 
// Example 1:
// 
// Input: "()())()"
// Output: ["()()()", "(())()"]
// Example 2:
// 
// Input: "(a)())()"
// Output: ["(a)()()", "(a())()"]
// Example 3:
// 
// Input: ")("
// Output: [""]

vector<string> removeInvalidParentheses(string s)
{
	vector<string> result;
	remove(&result, s, 0, 0, '(', ')');
	return result;
}

void remove(vector<string>* const result, string s, const int iStart, const int jStart, const char openedParenthesis, const char closedParenthesis)
{
	int stack = 0;
	for (unsigned int i = iStart; i < s.size(); ++i)
	{
		if (s[i] == openedParenthesis)
		{
			stack++;
		}
		else if (s[i] == closedParenthesis)
		{
			stack--;
		}
		
		if (stack >= 0)
		{
			continue;
		}
		
		for (unsigned int j = jStart; j <= i; ++j)
		{
			if ((s[j] == closedParenthesis) && (j == jStart || s[j - 1] != closedParenthesis))
			{
				remove(result, s.substr(0, j) + s.substr(j + 1, s.size() - j - 1), i, j, openedParenthesis, closedParenthesis);
			}
		}
		return;
	}
	
	std::reverse(s.begin(), s.end());
	
	if (openedParenthesis == '(')
	{
		remove(result, s, 0, 0,')', '(');
	}
	else
	{
		result->push_back(s);
	}
}