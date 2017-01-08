class Solution {
	func singleNumber(_ nums: [Int]) -> Int {
		// Reference: http://www.acmerblog.com/leetcode-single-number-ii-5394.html
		var bitArray:[Int] = []
		var result = 0
		for var bit in 0..<32{
			bitArray.append(0)
		}
		for var bit in 0..<32{
			for var index in 0..<nums.count{
				if ((nums[index] >> bit) & 1 != 0 ){
					bitArray[bit] += 1
				}
			}
			result |= ((bitArray[bit] % 3) << bit)
		}
		return result
	}
}