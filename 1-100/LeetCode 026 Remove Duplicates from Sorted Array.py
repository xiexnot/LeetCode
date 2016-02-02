#
#	Project		LeetCode 026 Remove Duplicates from Sorted Array
#	Author		Yifei Xie
#	Date		2016.01.25
#	Algorithm	Force Operation. Do not delete nums's memory or modify its address.
#	Complexity	Time:O(N) Space:O(N)
#


class Solution(object):
	def removeDuplicates(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		if len(nums) == 0:
			return 0
		j = 0
		for i in range(len(nums)):
			if nums[i] != nums[j]:
				nums[j+1], nums[i] = nums[i], nums[j+1]
				j += 1
		return j + 1