//
//  AddTwoNumbers.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/5/16.
//
//

public class ListNode {
	public var val: Int
	public var next: ListNode?

	init(_ val: Int) {
		self.val = val
		self.next = nil
	}
}

/// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
/// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
/// Output: 7 -> 0 -> 8
///
/// - parameter l1: list of digit node
/// - parameter l2: list of digit node
///
/// - returns: sum of two list of digit node
func addTwoNumbers(l1: ListNode?, l2: ListNode?) -> ListNode? {
	var l1 = l1
	var l2 = l2
	let result = ListNode(0)
	var i = result

	var carry = 0
	while l1 != nil || l2 != nil || carry == 1 {
		// Add digit
		var sum = carry
		if let n1 = l1 {
			sum += n1.val
		}
		if let n2 = l2 {
			sum += n2.val
		}

		// Update carry
		carry = sum / 10

		// Create new digit node for sum
		let node = ListNode(sum % 10)

		// Update result node
		i.next = node
		i = node

		// Next node
		l1 = l1?.next
		l2 = l2?.next
	}

	return result.next
}

/* Below functions are helper functions for unit test */

/// Creates list of digit node
/// For example: "423" turns into 3 -> 2 -> 4
///
/// - parameter numbers: non-negative numbers in string
///
/// - returns: the last digit node
func createDigits(numbers: String) -> ListNode? {
	let result = ListNode(0)
	var i = result
	for digit in numbers.characters.reversed() {
		let val = Int(String(digit))!
		let node = ListNode(val)
		i.next = node
		i = node
	}
	return result.next
}

/// Convert ListNode into String
/// For example: 3 -> 2 -> 4 converts to "423"
///
/// - parameter l: list of digit node
///
/// - returns: list of digit node in string
func listNodeInString(l: ListNode?) -> String {
	var l = l
	var digit = [String]()

	while l != nil {
		digit.append(String(l!.val))
		l = l!.next
	}

	return digit.reversed().joined(separator: "")
}
