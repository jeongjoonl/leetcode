//
//  ZigZagConversion.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/12/16.
//
//

/// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
/// (you may want to display this pattern in a fixed font for better legibility)
/// P   A   H   N
/// A P L S I I G
/// Y   I   R
/// And then read line by line: "PAHNAPLSIIGYIR"
/// Write the code that will take a string and make this conversion given a number of rows:
///
/// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
///
/// - parameter s:       arbitrary string
/// - parameter numRows: number of rows
///
/// - returns: zigzag pattern
func convert(s: String, numRows: Int) -> String {
	if numRows == 1 { return s }

	var result = [String](repeating: "", count: numRows)
	let loop = 2 * numRows - 2
	for i in 0..<s.characters.count {
		var index = i % loop
		
		if index > numRows - 1 {
			index = loop - index
		}

		result[index].append(s[i])
	}
	return result.joined(separator: "")
}

/// Get character at index i with subscript
/// For example:
///     let a = "hello"
///     a[0] is "h"
///     a[3] is "l"
private extension String {
	subscript (i: Int) -> Character {
		get {
			return self[self.index(self.startIndex, offsetBy: i)]
		}
	}
}
