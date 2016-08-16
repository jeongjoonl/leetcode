//
//  StringToInteger.swift
//  CodeChallenge
//
//  Created by Jeongjoon Lee on 8/15/16.
//
//

/// Convert a string to an integer.
/// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
/// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
///
/// - parameter str: string
///
/// - returns: integer
func myAtoi(str: String) -> Int? {
	let len = str.characters.count
	var result = 0
	var sign = 1
	var index = 0

	if str[0] == "-" {
		sign = -1
		index += 1
	}

	while index < len, let digit = Int(String(str[index])) {
		result = result * 10 + digit
		index += 1
	}

	return index < len ? nil : sign * result
}

private extension String {
	subscript(i: Int) -> Character {
		get {
			return self[self.index(self.startIndex, offsetBy: i)]
		}
	}
}

/// Using closure
func myAtoi2(str: String) -> Int? {
	var str = str
	var sign = 1

	if str[0] == "-" {
		sign = -1
		str = str.substring(from: str.index(after: str.startIndex))
	}

	let result = str.characters.reduce(0) { (acc: Int?, c: Character) -> Int? in
		if let acc = acc, let digit = Int(String(c)) {
			return acc * 10 + digit
		}
		return nil
	}

	return result != nil ? sign * result! : nil
}
