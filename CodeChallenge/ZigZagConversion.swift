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
	var result = [Character](repeating: " ", count: s.characters.count)
	var index = 0

	let loop = numRows * 2 - 2
	for row in 0..<numRows {
		
		let i = (row == numRows-1) ? loop : loop - row * 2
		let j = (i == loop)        ? loop : loop - i

		var iTurn = true
		var someNum = row
		while (someNum < s.characters.count && index < result.count) {
			result[index] = s[someNum]
			index += 1

			if iTurn {
				someNum += i
			} else {
				someNum += j
			}

			iTurn = !iTurn
		}
	}

	return String(result)
}

private extension String {
	subscript (i: Int) -> Character {
		get {
			return self[self.index(self.startIndex, offsetBy: i)]
		}
	}
}
