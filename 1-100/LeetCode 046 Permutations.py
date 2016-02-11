class Solution(object):
	def permute(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[List[int]]
		"""
		nums[0:] = sorted( nums[0:], reverse = False)
		global Result 
		Result = []
		self.copyResult(nums)
		while self.nextPermutation(nums)==True:
			self.copyResult(nums)
		return Result
	
	def copyResult(self, nums):
		result_combination = []
		for i in range(nums.__len__()):
			result_combination.append(nums[i])
		global Result
		Result.append(result_combination)
		return 0
	
	def nextPermutation(self, nums):
		"""
		:type nums: List[int]
		:rtype: void Do not return anything, modify nums in-place instead.
		"""
		for i in range(1,nums.__len__())[::-1]:
			if nums[i] > nums[i-1]:
				minindex = i
				for j in range(i,nums.__len__()):
					if nums[i-1] < nums[j] and nums[j] < nums[minindex]:
						minindex = j
				tmp = nums[minindex]
				nums[minindex] = nums[i-1]
				nums[i-1] = tmp
				nums[i:] = sorted(nums[i:], reverse=False)
				return True
		return False