#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 050
	题目：	计算Pow(x,n)
	解法：	n进行bit操作 每个位置如果是1则累乘
"""

class Solution(object):
	def get_pow(self, x, n):
		result = 1.0
		current = x
		while n!=0:
			if n & 1 ==0:
				pass
			else:
				result *= current
			current *= current
			n /= 2
		return result
	def myPow(self, x, n):
		"""
		:type x: float
		:type n: int
		:rtype: float
		"""
		if n == 0:
			return 1.0
		if n < 0:
			return 1.0 / Solution().get_pow(x,-n)
		return Solution().get_pow(x,n)