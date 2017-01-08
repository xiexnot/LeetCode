class Solution {
	func singleNumber(_ nums: [Int]) -> Int {
		// Using xor to summary in O(n)
		
		var xorResult = 0
		for var i in 0..<nums.count{
			xorResult = xorResult ^ nums[i]
		}
		return xorResult
	}
}