//
//  MedianOfTwoSortedArray.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/7/16.
//
//

/// Find the median of the two sorted arrays.
///
/// Example 1:
/// nums1 = [1, 3]
/// nums2 = [2]
/// The median is 2.0
///
/// Example 2:
/// nums1 = [1, 2]
/// nums2 = [3, 4]
/// The median is (2 + 3)/2 = 2.5
///
/// - parameter nums1: sorted array
/// - parameter nums2: sorted array
///
/// - returns: median of the two sorted arrays
func findMedianSortedArrays( nums1: [Int], nums2: [Int]) -> Double? {
	var nums1 = nums1
	var nums2 = nums2

	// Length of the two sorted arrays
	var m = nums1.count
	var n = nums2.count

	// Choose shorter array
	if m > n {
		// Swap two sorted arrays and its length
		(nums1, nums2) = (nums2, nums1)
		(m, n) = (n, m)
	}

	// i for the nums1 index and j for the nums2 index
	var i = 0, j = 0
	var imin = 0, imax = m

	while true {
		i = (imin + imax) / 2
		j = (m + n + 1) / 2 - i

		if j > 0 && i < m && nums2[j-1] > nums1[i] {
			imin = i + 1
		} else if i > 0 && j < n && nums1[i-1] > nums2[j] {
			imax = i - 1
		} else {
			break
		}
	}

	var maxLeft: Int?
	if i == 0 {
		maxLeft = nums2[j-1]
	} else if j == 0 {
		maxLeft = nums1[i-1]
	} else {
		maxLeft = max(nums1[i-1], nums2[j-1])
	}

	if (m + n) % 2 == 1 {
		return Double(maxLeft!)
	}

	var minRight: Int?
	if i == m {
		minRight = nums2[j]
	} else if j == n {
		minRight = nums1[i]
	} else {
		minRight = min(nums1[i], nums2[j])
	}

	return Double(maxLeft! + minRight!) / 2.0
}
