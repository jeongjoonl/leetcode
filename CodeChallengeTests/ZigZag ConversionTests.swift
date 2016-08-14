//
//  ZigZag ConversionTests.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/12/16.
//
//

import XCTest

class ZigZag_ConversionTests: XCTestCase {
	func testConvert() {
		XCTAssertEqual(convert(s: "PAYPALISHIRING", numRows: 3), "PAHNAPLSIIGYIR")

		XCTAssertEqual(convert(s: "abcdefg", numRows: 1), "abcdefg")
		XCTAssertEqual(convert(s: "abcdefg", numRows: 2), "acegbdf")
		XCTAssertEqual(convert(s: "abcdefg", numRows: 3), "aebdfcg")
		XCTAssertEqual(convert(s: "abcdefghij", numRows: 4), "agbfhceidj")
		XCTAssertEqual(convert(s: "abcdefghijklm", numRows: 5), "aibhjcgkdflem")
		XCTAssertEqual(convert(s: "abcdefghijklmnop", numRows: 6), "akbjlcimdhnegofp")
		XCTAssertEqual(convert(s: "abcdefghijklmnopqrs", numRows: 7), "amblnckodjpeiqfhrgs")
	}
}
