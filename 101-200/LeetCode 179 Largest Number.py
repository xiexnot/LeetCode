class Solution:
	# @param {integer[]} nums
	# @return {string}

	def compare(self, A, B):
		return -1 if A + B < B + A else 1
	def swap(self, a,b):
		return b , a
	def largestNumber(self, nums):
		if nums is None:
			return ""
		nums = [str(item) for item in nums]
		for IndexI in range(nums.__len__()):
			for IndexJ in range(IndexI+1, nums.__len__()):
				if self.compare(nums[IndexI], nums[IndexJ]) < 0:
					nums[IndexI], nums[IndexJ] = self.swap(nums[IndexI], nums[IndexJ])
		result = ""
		for item in nums:
			result += item
		while result.__len__() > 1 and result[0] == '0':
			result = result[1:]
		return result
