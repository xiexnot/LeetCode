//	在原来的Array基础上复制值以生成新的Array
// 同时保存Previous_1和Previous_2(当前数字的前两个有效数字)

class Solution {
	func removeDuplicates(_ nums: inout [Int]) -> Int {
		if nums.count <= 2{
			return nums.count 
		}
		var ArrayIndex = 1
		var Previous_2 : Int;
		var Previous_1 : Int;
		Previous_2 = nums[0]
		Previous_1 = nums[1]
		for Index in 2..<nums.count{
			//	和前一个数字不同
			//	和前一个数字相同但和前两个数字不同
			if (nums[Index] != Previous_1 || (nums[Index] == Previous_1 && nums[Index] != Previous_2))
			{
				Previous_2 = Previous_1
				Previous_1 = nums[Index]
				ArrayIndex += 1
				nums[ArrayIndex] = nums[Index]
				//	复制构造新Array 
			}
		}
		return ArrayIndex+1
	}
}