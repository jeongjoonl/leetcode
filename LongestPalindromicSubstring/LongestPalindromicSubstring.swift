//
//  LongestPalindromicSubstring.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/10/16.
//
//

/// Finds the longest palindromic substring in string S.
/// This is Manacher's algorithm
///
/// - parameter s: arbitrary string
///
/// - returns: longest palindromic substring
func longestPalindrome(s: String) -> String {
	let chArray = transformString(s: s)
	let len = chArray.count

	var p = [Int](repeating: 0, count: len)
	var center = 0
	var right = 0

	for i in 1..<len {
		if i < right {
			let mirr = 2 * center - i
			p[i] = min(p[mirr], right - i)
		}

		var expandLeft  = i - (p[i] + 1)
		var expandRight = i + (p[i] + 1)

		while expandLeft >= 0 && expandRight < len && chArray[expandLeft] == chArray[expandRight] {
			p[i] += 1
			expandLeft -= 1
			expandRight += 1
		}

		if i + p[i] > right {
			center = i
			right = i + p[i]
		}
	}

	var argmax = 0
	for i in 1..<p.count {
		if p[argmax] < p[i] {
			argmax = i
		}
	}

	let range = argmax-p[argmax]...argmax+p[argmax]

	return String(chArray[range].filter{$0 != "#"})
}

func transformString(s: String) -> [Character] {
	var chArray = [Character](repeating: "#", count: s.characters.count * 2 + 1)

	for index in s.characters.indices {
		let i = s.distance(from: s.startIndex, to: index)
		chArray[i*2 + 1] = s[index]
	}

	return chArray
}
