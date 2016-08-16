//
//  StringToIntegerTests.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/15/16.
//
//

import XCTest

class StringToIntegerTests: XCTestCase {
	func testMyAtoi() {
		XCTAssertEqual(myAtoi(str: "123"), 123)
		XCTAssertEqual(myAtoi(str: "-123"), -123)
		XCTAssertEqual(myAtoi(str: "923912312312326432"), 923912312312326432)
		XCTAssertEqual(myAtoi(str: "-923912312312326432"), -923912312312326432)
		XCTAssertEqual(myAtoi(str: "123-"), nil)
		XCTAssertEqual(myAtoi(str: "a123"), nil)
		XCTAssertEqual(myAtoi(str: "1b23"), nil)
		XCTAssertEqual(myAtoi(str: "-123c"), nil)
		XCTAssertEqual(myAtoi(str: "-12z3"), nil)
	}
}
