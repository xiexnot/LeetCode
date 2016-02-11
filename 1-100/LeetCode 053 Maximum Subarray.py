class Solution(object):
	def maxSubArray(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		if len(nums) == 0:
			return 0
		D = []
		for i in range(len(nums)):
			D.append(nums[i])
		for i in range(1,len(nums)):
			D[i] = max(D[i], D[i-1]+nums[i])
		result = D[0]
		for i in range(0,len(nums)):
			result = max(result, D[i])
		return result