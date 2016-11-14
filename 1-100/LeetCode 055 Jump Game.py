#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 055
	题目：	青蛙跳石头问题
			Given an array of non-negative integers, you are initially positioned at the first index of the array.
			Each element in the array represents your maximum jump length at that position.
			Determine if you are able to reach the last index.
	解法：	Greedy O(N) 暴力做法 O(N^2)
			can[i]为跳到（过）第i-th石头时 剩下的还可以往前跳跃的步数
			两种情况
			1. 跳到这一步 而后从这一步重新开始算新步数
			2. 从之前的某一步跳过来 在i-th位置划过（然而不落地）
"""

def max(a,b):
	if a>b:
		return a
	return b

class Solution(object):
	def canJump(self, nums):
		"""
		:type nums: List[int]
		:rtype: bool
		"""
		can = []
		for i in range(nums.__len__()):
			can.append(-1)
		can[0] = nums[0]
		for i in range(1, nums.__len__()):
			if can[i-1] >0:
				can[i] = max(nums[i], can[i-1]-1)
			else:
				can[i] = -1
		if can[nums.__len__()-1] == -1 and nums.__len__()>1:
			return False
		return True