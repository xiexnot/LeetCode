#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 035
	题目：	判断读入的sudoku是不是有可行解的（只要判断数字出现的频率就好 不用求解）
	解法：	暴力
	注意：	9*9 sudoku不需要判断大的对角线
"""


class Solution(object):
	def check_horizon(self,board):
		for i in range(9):
			hash_table = []
			for j in range(9):
				if board[i][j] == ".":
					continue
				if board[i][j] in hash_table:
					return False
				hash_table.append(board[i][j])
		print "#1"
		return True

	def check_vertical(self, board):
		for j in range(9):
			hash_table = []
			for i in range(9):
				if board[i][j] == ".":
					continue
				if board[i][j] in hash_table:
					return False
				hash_table.append(board[i][j])
		print "#2"
		return True

	def check_minibox(self, board, starting, ending):
		hash_table = []
		for i in range(3):
			for j in range(3):
				if board[i+starting][j+ending] == ".":
					continue
				if board[i+starting][j+ending] in hash_table:
					return False
				hash_table.append(board[i+starting][j+ending])
		return True

	def check_box(self, board):
		for i in range(3):
			for j in range(3):
				starting = i * 3
				ending = j * 3
				if Solution().check_minibox(board, starting, ending) == False:
					return False
		return True

	"""
		9*9 sudoku不需要判断大的对角线
	"""

	def check_cross(self, board):
		hash_table = []
		for i in range(9):
			j = i
			if board[i][j] == ".":
				continue
			if board[i][j] in hash_table:
				return False
			hash_table.append(board[i][j])
		hash_table = []
		for i in range(9):
			j = 9 - i - 1
			if board[i][j] == ".":
				continue
			if board[i][j] in hash_table:
				return False
			hash_table.append(board[i][j])
		return True

	def isValidSudoku(self, board):
		"""
		:type board: List[List[str]]
		:rtype: bool
		"""
		if Solution().check_horizon(board) and Solution().check_vertical(board) and Solution().check_box(board):
			return True
		else:
			return False

if __name__ == "__main__":
	print Solution().isValidSudoku(["........2","......6..","..14..8..",".........",".........","....3....","5.86.....",".9....4..","....5...."])