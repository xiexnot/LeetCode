#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 062
	题目：	矩阵地图，左上到右下的路径数量
	解法：	DP
"""

class Solution(object):
	def uniquePaths(self, m, n):
		"""
		:type m: int
		:type n: int
		:rtype: int
		"""
		if n == 0 or m == 0:
			return 0
		result = []
		for i in range(m):
			result_item = []
			for j in range(n):
				result_item.append(0)
			result.append(result_item)
		result[0][0] = 1
		for i in range(m):
			for j in range(n):
				if i-1>=0:
					result[i][j] += result[i-1][j]
				if j-1>=0:
					result[i][j] += result[i][j-1]
		return result[m-1][n-1]