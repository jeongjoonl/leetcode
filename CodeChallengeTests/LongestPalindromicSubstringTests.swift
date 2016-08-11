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

		var result = longestPalindrome(s: "aaaaaaaaaaaaaaaaaa")
		XCTAssertEqual(result, "aaaaaaaaaaaaaaaaaa")

		result = longestPalindrome(s: "aaabcdefggfedcbggih")
		XCTAssertEqual(result, "bcdefggfedcb")

		result = longestPalindrome(s: "aaabcdefghijklmnoponmlkjihgfedcbabcdef")
		XCTAssertEqual(result, "abcdefghijklmnoponmlkjihgfedcba")
	}
}
