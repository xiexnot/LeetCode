#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 035
	题目：	用o(logn)的时间 找到有序a[]中可以插入target的位置 使得新生成的a[]有序
	解法：	二分
"""

class Solution(object):
	def searchInsert(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: int
		"""

		if nums.__len__() == 0:
			return 0
		left = 0
		right = nums.__len__()-1
		if nums[left] >= target:
			return left
		while left <= right:
			center = (left+right)
			if nums[center] == target:
				return center
			elif nums[center] < target:
				left = center + 1
			else:
				right = center - 1
		return left
