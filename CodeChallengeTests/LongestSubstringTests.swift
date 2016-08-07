//
//  LongestSubstringTests.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/6/16.
//
//

import XCTest

class LongestSubstringTests: XCTestCase {
	func testLengthOfLongestSubstring() {
		// String: "abcabcddd", Substring "abc" -> 3
		var result = lengthOfLongestSubstring(s: "abcabcddd")
		XCTAssertEqual(result, 3)

		// String "aaaaaaaaaaaaa", Substring "a" -> 1
		result = lengthOfLongestSubstring(s: "aaaaaaaaaaaaa")
		XCTAssertEqual(result, 1)

		// String "pwwkew", Substring "wke" -> 1
		result = lengthOfLongestSubstring(s: "pwwkew")
		XCTAssertEqual(result, 3)

		// String "abcdefcabgd" Substring "defcabg" -> 7
		result = lengthOfLongestSubstring(s: "abcdefcabgd")
		XCTAssertEqual(result, 7)

		// String "abcdefcabghi" Substring "defcabghi" -> 9
		result = lengthOfLongestSubstring(s: "abcdefcabgd")
		XCTAssertEqual(result, 9)

		// String "abcdefcccdehi" Substring "abcdef" -> 6
		result = lengthOfLongestSubstring(s: "abcdefcabgd")
		XCTAssertEqual(result, 6)
	}
}
