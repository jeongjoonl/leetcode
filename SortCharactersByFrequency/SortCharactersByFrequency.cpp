// SortCharactersByFrequency.cpp
// Created by Jeongjoon Lee on 4/23/2019.

// Given a string, sort it in decreasing order based on the frequency of characters.
//
// Example 1:
//
// Input:
// "tree"
//
// Output:
// "eert"
//
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:
//
// Input:
// "cccaaa"
//
// Output:
// "cccaaa"
//
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:
//
// Input:
// "Aabb"
//
// Output:
// "bbAa"
//
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

string frequencySort(string s)
{
    string result(s.size(), ' ');
    
    map<char, int> frequences;
    for (const auto& c : s)
    {
        ++frequences[c];
    }
    
    map<int, vector<char>> bucket;
    for (const auto& f : frequences)
    {
        if (bucket.find(f.second) == bucket.end())
        {
            bucket[f.second] = vector<char>();
        }
        
        bucket[f.second].push_back(f.first);
    }
    
    int pos = 0;
    for(auto iter = bucket.rbegin(); iter != bucket.rend(); ++iter)
    {
        for (const auto& c : iter->second)
        {
            for (size_t i = 0; i < iter->first; ++i)
            {
                result[pos + i] = c;
            }
            
            pos += iter->first;
        }
    }
    
    return result;
}
