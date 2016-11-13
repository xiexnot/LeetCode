#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 051
	题目：	N皇后问题
	解法：	DFS
			\对角线 i-j
			/对角线 i+j
"""

class Solution(object):
	def add_solution(self,n):
		global current
		global result
		current_result = []
		for i in range(n):
			current_result_item = ""
			for j in range(n):
				if j != current[i]:
					current_result_item += "."
				else:
					current_result_item += 'Q'
			current_result.append(current_result_item)	
		result.append(current_result)
		return 0

	def DFS(self, x, n):
		if x == n:
			Solution().add_solution(n)
			return 0
		global current, cross_2, cross_1
		for i in range(0,n):
			if (i not in current) and ((x-i) not in cross_1) and ((x+i) not in cross_2):
				# add queen
				current[x] = i
				cross_1[x] = x-i
				cross_2[x] = x+i
				# next step
				Solution().DFS(x+1,n)
				# delete queen
				current[x] = -1
				cross_1[x] = -MAXINT
				cross_2[x] = -MAXINT
		return 0
	def solveNQueens(self, n):
		"""
		:type n: int
		:rtype: List[List[str]]
		"""
		global cross_1, cross_2
		global current 
		global result
		global MAXINT
		MAXINT = 100000
		result = []
		current = []
		cross_1 = []
		cross_2 = []
		for i in range(2*n+1):
			cross_1.append(-MAXINT)
			cross_2.append(-MAXINT)
		for i in range(n):
			current.append(-1)
		Solution().DFS(0,n)

		return result