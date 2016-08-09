//
//  TwoSum.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/5/16.
//
//

/// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
/// You may assume that each input would have exactly one solution.
///
/// Example:
/// Given nums = [2, 7, 11, 15], target = 9,
///
/// Because nums[0] + nums[1] = 2 + 7 = 9,
/// return [0, 1].
///
/// - parameter nums:   list of arbitrary numbers
/// - parameter target: arbitrary numbers
///
/// - returns: indices of the two numbers in list that sum up to target number
func twoSum(nums: [Int], target: Int) -> [(Int, Int)] {
	var answers = [(Int, Int)]()
	var map = [Int:Int]()

	for i in 0..<nums.count {
		let num = nums[i]

		map[num] = i

		if let j = map[target - num] {
			answers.append( (j, i) )
		}
	}

	return answers
}
