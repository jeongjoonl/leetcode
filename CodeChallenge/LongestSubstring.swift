//
//  LongestSubstring.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/6/16.
//
//

/// Given a string, find the length of the longest substring without repeating characters.
///
/// Examples:
/// Given "abcabcbb", the answer is "abc", which the length is 3.
/// Given "bbbbb", the answer is "b", with the length of 1.
/// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
///
/// - parameter s: sequence of arbitrary characters
///
/// - returns: length of the longest substring without repeating characters
func lengthOfLongestSubstring(s: String) -> Int {

	var start = -1, result = 0
	var map = [Character:Int]()

	for index in s.characters.indices {
		let key = s[index]
		let i = s.distance(from: s.startIndex, to: index)

		if let val = map[key] {
			start = max(start, val)
		}

		map[key] = i

		result = max(result, i - start)
	}
	return result
}
