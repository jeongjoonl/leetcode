// ValidParenthese.cpp
// Created by Jeongjoon Lee on 3/3/2019.

//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//    Open brackets must be closed by the same type of brackets.
//    Open brackets must be closed in the correct order.
//
//Note that an empty string is also considered valid.

bool isValid(string s)
{
	stack<char> brackets;

	bool bValid = true;
	for (const char& C : s)
	{
		if (C == '(')
		{
			brackets.push(')');
		}
		else if (C == '{')
		{
			brackets.push('}');
		}
		else if (C == '[')
		{
			brackets.push(']');
		}
		else if (!brackets.empty() && C == brackets.top())
		{
			brackets.pop();
		}
		else
		{
			bValid = false;
			break;
		}
	}

	return brackets.empty() && bValid;
}