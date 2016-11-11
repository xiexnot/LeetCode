"""
	LeetCode 016 3Sum Cloest
	题目：	给定数组a和target 在a中选择3个数字使得和最接近target
	解1：	使用O(n^2)的方法解3Sum问题 过程中不断更新和target的差距
"""

def min(a,b):
	if a<b:
		return a
	return b

def get_result(existing_result, current, target):
	if abs(existing_result - target) < abs(current - target):
		return existing_result
	return current

class Solution(object):
	def threeSumClosest(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: int
		"""
		nums.sort()
		result = 100000000
		for i in range(nums.__len__()-2):
			goal = target - nums[i] 
			left = i + 1
			right = nums.__len__()-1
			result = get_result(result, nums[left]+nums[i]+nums[right], target) #如果找不到最优解 则记录下当前的情况

			while left < right:
				if nums[left] + nums[right] == goal:
					result = get_result(result, nums[left]+nums[i]+nums[right], target)
					return result
				elif nums[left] + nums[right] < goal:
					result = get_result(result, nums[left]+nums[i]+nums[right], target)
					while left < right:
						left += 1
						if nums[left] != nums[left-1]:
							break
				else:
					result = get_result(result, nums[left]+nums[i]+nums[right], target)
					while left < right:
						right -= 1
						if nums[right] != nums[right+1]:
							break
		return result