#
#	Project		LeetCode 027 Remove Element
#	Author		Yifei Xie
#	Date		2016.01.25
#	Algorithm	Force Operation. Do not delete nums's memory or modify its address.
#	Complexity	Time:O(N^2) Space:O(N)
#

class Solution(object):
	def removeElement(self, nums, val):
		"""
		:type nums: List[int]
		:type val: int
		:rtype: int
		"""
		if len(nums) == 0:
			return 0
	#	print len(nums)
		old_length = len(nums)
		delete_length = 0
		i = len(nums) - 1
		while True:
			if i < 0:
				break
			if nums[i] == val:
				for j in range(i,len(nums)-1):
					nums[j] = nums[j+1]
				delete_length += 1
			i = i - 1
		return old_length - delete_length
	