//
//  ReverseInteger.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/14/16.
//
//

/// Reverse digits of an integer.
///
/// Example1: x = 123, return 321
/// Example2: x = -123, return -321
///
/// - parameter x: integer
///
/// - returns: reversed digits of integer
func reverse(x: Int) -> Int {
	var x = x
	var result = 0
	while x != 0 {
		result = result * 10 + (x % 10)
		x /= 10
	}
	return result
}
