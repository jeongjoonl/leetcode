//
//  ReverseIntegerTests.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/14/16.
//
//

import XCTest

class ReverseIntegerTests: XCTestCase {
	func testReverse() {
		XCTAssertEqual(reverse(x: 123), 321)
		XCTAssertEqual(reverse(x: -123), -321)
		XCTAssertEqual(reverse(x: 0), 0)
		XCTAssertEqual(reverse(x: 123450), 54321)
		XCTAssertEqual(reverse(x: -123450), -54321)
		XCTAssertEqual(reverse(x: 12345012342), 24321054321)
		XCTAssertEqual(reverse(x: -12345012342), -24321054321)
	}
}
