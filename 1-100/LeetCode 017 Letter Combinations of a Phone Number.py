#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 017
	题目：	拨号键盘之翻译
	解法：	DFS
"""

number_matrix = [
	[],[],["a","b","c"],["d","e","f"],["g","h","i"],["j","k","l"],["m","n","o"],["p","q","r","s"],["v","t","u"],["y","z","w","x"]
]

def DFS(digits, current):
	global number_matrix
	if digits.__len__() == current.__len__():
		if current != "": #如果是空串 则不加入答案
			result.append(current)
		return 0
	i = current.__len__()
	for item in number_matrix[int(digits[i])]:
		DFS(digits, current+item)
	return 0

class Solution(object):
	def letterCombinations(self, digits):
		"""
		:type digits: str
		:rtype: List[str]
		"""
		global result
		result = []
		DFS(digits,"")
		return result