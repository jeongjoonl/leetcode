//
//  MedianOfTwoSortedArrayTests.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/7/16.
//
//

import XCTest

class MedianOfTwoSortedArrayTests: XCTestCase {
	func testFindMedianSortedArrays() {
		var result = findMedianSortedArrays(nums1: [1,3], nums2: [2])
		XCTAssertEqual(result, 2.0)

		result = findMedianSortedArrays(nums1: [1,3], nums2: [2, 4])
		XCTAssertEqual(result, 2.5)

		result = findMedianSortedArrays(nums1: [1,3,4,6,8,10,13], nums2: [2,7,11,23])
		XCTAssertEqual(result, 7.0)
	}
}
