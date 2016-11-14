#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 063
	题目：	有障碍的矩阵地图，左上到右下的路径数量
	解法：	DP
	注意：	起点为obstacle的情况
"""

class Solution(object):
	def uniquePathsWithObstacles(self, obstacleGrid):
		"""
		:type obstacleGrid: List[List[int]]
		:rtype: int
		"""
		if obstacleGrid == []:
			return 0
		m = obstacleGrid.__len__()
		n = obstacleGrid[0].__len__()
		result = []
		for i in range(m):
			result_item = []
			for j in range(n):
				result_item.append(0)
			result.append(result_item)
		if obstacleGrid[0][0] == 1:
			result[0][0] = 0
		else:
			result[0][0] = 1
		for i in range(m):
			for j in range(n):
				if obstacleGrid[i][j] == 1:
					continue
				if i-1>=0:
					result[i][j] += result[i-1][j]
				if j-1>=0:
					result[i][j] += result[i][j-1]
		return result[m-1][n-1]