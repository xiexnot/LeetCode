#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 054
	题目：	环绕输出矩阵元素
	解法：	暴力解法
	注意：	输入为空matrix时的结果
"""

Direction = [
	[0,+1],
	[+1,0],
	[0,-1],
	[-1,0]
]

class Solution(object):
	def DFS(self,matrix, x, y, dir):
		global Direction
		global n,m
		global hashtable
		hashtable[x][y] = True
		result.append(matrix[x][y])
		for i in range(4):
			new_x = x + Direction[(dir+i)%4][0]
			new_y = y + Direction[(dir+i)%4][1]
			if new_x >=0 and new_x < m and new_y >= 0 and new_y < n and hashtable[new_x][new_y] == False:
				Solution().DFS(matrix, new_x, new_y, (dir+i)%4)
				break
		return 0

	def spiralOrder(self, matrix):
		"""
		:type matrix: List[List[int]]
		:rtype: List[int]
		"""
		global m,n
		if matrix == []:
			return []
		m = matrix.__len__()
		n = (matrix[0]).__len__()
		global result
		global hashtable
		result = []
		hashtable = []
		for i in range(m):
			hashtable_item = []
			for j in range(n):
				hashtable_item.append(False)
			hashtable.append(hashtable_item)
		Solution().DFS(matrix,0,0,0)
		return result
