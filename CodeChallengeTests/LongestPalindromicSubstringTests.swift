//
//  LongestPalindromicSubstringTests.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/10/16.
//
//

import XCTest

class LongestPalindromicSubstringTests: XCTestCase {
	func testLongestPalindrome() {
		var result = longestPalindrome(s: "a")
		XCTAssertEqual(result, "a")

		result = longestPalindrome(s: "aa")
		XCTAssertEqual(result, "aa")

		result = longestPalindrome(s: "aaa")
		XCTAssertEqual(result, "aaa")

		result = longestPalindrome(s: "aba")
		XCTAssertEqual(result, "aba")

		result = longestPalindrome(s: "aaaaa")
		XCTAssertEqual(result, "aaaaa")

		result = longestPalindrome(s: "aaaaaa")
		XCTAssertEqual(result, "aaaaaa")

		result = longestPalindrome(s: "aaabcdefggfedcbggih")
		XCTAssertEqual(result, "bcdefggfedcb")

		result = longestPalindrome(s: "aaabcdefghijklmnoponmlkjihgfedcbabcdef")
		XCTAssertEqual(result, "abcdefghijklmnoponmlkjihgfedcba")
	}
}

