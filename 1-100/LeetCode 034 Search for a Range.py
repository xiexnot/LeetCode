#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 034
	题目：	用o(logn)的算法在长度n的数组里找i,j使得a[i]到a[j]均为target
	解法：	二分法为核心
			然而改成二分法成立时找最左和二分法成立时找最右
			此时时间效率为2logn=o(logn)
"""

def FindLeftAnchor(nums, target):
	result = -1
	left = 0
	right = nums.__len__()-1
	while left<right:
		center = (left+right) / 2
		if nums[center] == target:
			result = center
			right = center - 1
		elif nums[center] < target:
			left = center + 1
		else:
			right = center - 1

	if left == right and nums[left] == target:
		result = left
	return result


def FindRightAnchor(nums, target):
	result = -1
	left = 0
	right = nums.__len__()-1
	while left<right:
		center = (left+right) / 2
		if nums[center] == target:
			result = center
			left = center + 1
		elif nums[center] < target:
			left = center + 1
		else:
			right = center - 1

	if left == right and nums[left] == target:
		result = left
	return result

class Solution(object):
	def searchRange(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: List[int]
		"""
		starting = FindLeftAnchor(nums, target)
		ending = FindRightAnchor(nums, target)
		return [starting, ending]

if __name__=="__main__":
	print Solution().searchRange([5, 7, 7, 8, 8, 10],8)