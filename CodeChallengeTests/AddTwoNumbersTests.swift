//
//  AddTwoNumbersTests.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/5/16.
//
//

import XCTest

class AddTwoNumbersTests: XCTestCase {
	func testAddTwoNumbers() {
		/* CASE 1 */
		// number 123: 3 -> 2 -> 1
		var l1 = createDigits(numbers: "123")
		// number 512: 2 -> 1 -> 5
		var l2 = createDigits(numbers: "512")

		// Expected sum: 635
		var sum = addTwoNumbers(l1: l1, l2: l2)
		var val = listNodeInString(l: sum)
		XCTAssertEqual(val, "635")

		/* CASE 2 */
		// number 12: 2 -> 1
		l1 = createDigits(numbers: "12")
		// number 3: 3
		l2 = createDigits(numbers: "3")

		// Expected sum: 15
		sum = addTwoNumbers(l1: l1, l2: l2)
		val = listNodeInString(l: sum)
		XCTAssertEqual(val, "15")

		/* CASE 3 */
		// number 923: 3 -> 2 -> 9
		l1 = createDigits(numbers: "923")
		// number 889: 9 -> 8 -> 8
		l2 = createDigits(numbers: "889")

		// Expected sum: 1812
		sum = addTwoNumbers(l1: l1, l2: l2)
		val = listNodeInString(l: sum)
		XCTAssertEqual(val, "1812")

		/* CASE 4 */
		// number 9999999: 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9
		l1 = createDigits(numbers: "9999999")
		// number 9: 9
		l2 = createDigits(numbers: "9")

		// Expected sum: 10000008
		sum = addTwoNumbers(l1: l1, l2: l2)
		val = listNodeInString(l: sum)
		XCTAssertEqual(val, "10000008")

		/* CASE 5 */
		// number 923: 3 -> 2 -> 9
		l1 = createDigits(numbers: "923")

		// Expected sum: 923
		sum = addTwoNumbers(l1: l1, l2: nil)
		val = listNodeInString(l: sum)
		XCTAssertEqual(val, "923")

		/* CASE 6 */
		// number 45
		l2 = createDigits(numbers: "45")

		// Expected sum: 945
		sum = addTwoNumbers(l1: nil, l2: l2)
		val = listNodeInString(l: sum)
		XCTAssertEqual(val, "45")

		/* CASE 7 */
		// Expected sum: nil
		sum = addTwoNumbers(l1: nil, l2: nil)
		XCTAssertNil(sum)

		/* CASE 8 */
		l1 = createDigits(numbers: "2432432432432432432432432432432432432432432432432432432432439")
		l2 = createDigits(numbers: "5642432432432432432432432432432432432432432432432432432439999")

		sum = addTwoNumbers(l1: l1, l2: l2)
		val = listNodeInString(l: sum)
		XCTAssertEqual(val, "8074864864864864864864864864864864864864864864864864864872438")
	}
}
