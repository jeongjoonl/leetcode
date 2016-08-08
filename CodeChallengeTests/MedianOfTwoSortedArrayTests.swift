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

		result = findMedianSortedArrays(nums1: [2,7,11,23], nums2: [1,3,4,6,8,10,13])
		XCTAssertEqual(result, 7.0)

		result = findMedianSortedArrays(nums1: [2, 100, 200], nums2: [1, 3, 4, 5, 6, 7])
		XCTAssertEqual(result, 5.0)

		result = findMedianSortedArrays(nums1: [2, 2, 2], nums2: [2, 2])
		XCTAssertEqual(result, 2.0)

		result = findMedianSortedArrays(nums1: [2, 2, 2], nums2: [2, 2, 2])
		XCTAssertEqual(result, 2.0)
	}
}
