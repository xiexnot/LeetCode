#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 056
	题目：	Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
	解法：	暴力解法
"""


Direction = [
	[0,+1],
	[+1,0],
	[0,-1],
	[-1,0]
]

class Solution(object):
	def DFS(self, n,x,y,dir):
		global result, Direction, count
		count += 1
		result[x][y] = count
		for i in range(4):
			new_x = x + Direction[(dir+i)%4][0]
			new_y = y + Direction[(dir+i)%4][1]
			if new_x >=0 and new_x < n and new_y >= 0 and new_y < n and result[new_x][new_y] == 0:
				Solution().DFS(n, new_x, new_y, (dir+i)%4)
				break
		return 0
	def generateMatrix(self, n):
		"""
		:type n: int
		:rtype: List[List[int]]
		"""
		global result, count
		result = []
		count = 0
		for i in range(n):
			result_item = []
			for j in range(n):
				result_item.append(0)
			result.append(result_item)
		if n>0:
			Solution().DFS(n,0,0,0)
		return result