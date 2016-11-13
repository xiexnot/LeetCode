#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 049
	题目：	给定list,将相同元素的List组合成group而后返回
	解法：	build binary tree来判断是否相同
"""

def get_str_sort(data):
	data = list(data)
	data.sort()
	result = ""
	for item in data:
		result += str(item)
	return result

class Node:
	def __init__(self, data):
		self.left = None
		self.right = None
		self.label = get_str_sort(data)
		self.data = [data]

class Solution(object):
	def get_all_group(self, x):
		if x == None:
			return []
		result = []
		if x.left != None:
			result += (Solution().get_all_group(x.left))
		if x.right != None:
			result += (Solution().get_all_group(x.right))
		result.append(x.data)
		return result

	def insert_str(self, head_pointer, str_item):
		x = head_pointer
		current_label = get_str_sort(str_item)
		while True:
			if x.label == current_label:
				x.data.append(str_item)
				break
			elif x.label < current_label:
				pass
				if x.right != None:
					x = x.right
				else:
					x.right = Node(str_item)
					break
			else:
				if x.left != None:
					x = x.left
				else:
					x.left = Node(str_item)
					break
		return 0

	def groupAnagrams(self, strs):
		"""
		:type strs: List[str]
		:rtype: List[List[str]]
		"""
		head_pointer = Node(strs[0])
		for str_item in strs[1:]:
			Solution().insert_str(head_pointer, str_item)
		return Solution().get_all_group(head_pointer)
