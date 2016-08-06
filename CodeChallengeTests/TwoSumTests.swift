//
//  TwoSumTests.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/5/16.
//
//

import XCTest

class TwoSumTests: XCTestCase {
	func testTwoSum() {
		// Case: no answer
		var ans = twoSum(nums: [10, 2, 13, 11, 5, 8, 4], target: 11)
		XCTAssert(ans.isEmpty)

		// Case: single answer
		ans = twoSum(nums: [2, 7, 11, 15], target: 9)
		XCTAssert(ans.contains { $0 == (0, 1) })

		ans = twoSum(nums: [11, 7, 15, 2], target: 9)
		XCTAssert(ans.contains { $0 == (1, 3) })

		// Case: multiple answer
		ans = twoSum(nums: [8, 5, 4, 12, 6, 7, 3, 20, 1, 2], target: 9)
		XCTAssert(ans.contains { $0 == (0, 8) })
		XCTAssert(ans.contains { $0 == (1, 2) })
		XCTAssert(ans.contains { $0 == (4, 6) })
		XCTAssert(ans.contains { $0 == (5, 9) })


	}
}
