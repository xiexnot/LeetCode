#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 048
	题目：	in-place的方式顺时针90度旋转image
	解法：	(i,j)->(j,length-1-i)->(length-i-1,length-j-1)->(length-1-j,i)->(i,j) 为一个旋转置换group，枚举(i,j)做置换即可
			当length为偶数时 i,j枚举条件为 [1,length/2]
			当length为奇数时 i,j枚举条件为 i: [1,length/2] j: [1,length/2+1]
"""

class Solution(object):

	def rotate_group(self,a,b,c,d):
		pass
		return d,a,b,c
	def rotate(self, matrix):
		"""
		:type matrix: List[List[int]]
		:rtype: void Do not return anything, modify matrix in-place instead.
		"""
		
		length = matrix.__len__()
		if length % 2 == 0:
			#transfer parted matrix (when matrix_n is even)
			for i in range(length/2):
				for j in range(length/2):
					x1 = i
					y1 = j
					x2 = j
					y2 = length - i - 1
					x3 = length - i - 1
					y3 = length - j - 1
					x4 = length - j - 1
					y4 = i
					matrix[x1][y1], matrix[x2][y2], matrix[x3][y3], matrix[x4][y4] = Solution().rotate_group(matrix[x1][y1], matrix[x2][y2], matrix[x3][y3], matrix[x4][y4])
		else:
			#transfer parted matrix (when matrix_n is odd)
			for i in range(length/2):
				for j in range(length/2+1):
					x1 = i
					y1 = j
					x2 = j
					y2 = length - i - 1
					x3 = length - i - 1
					y3 = length - j - 1
					x4 = length - j - 1
					y4 = i
					matrix[x1][y1], matrix[x2][y2], matrix[x3][y3], matrix[x4][y4] = Solution().rotate_group(matrix[x1][y1], matrix[x2][y2], matrix[x3][y3], matrix[x4][y4])
