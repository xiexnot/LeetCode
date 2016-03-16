#
#	Project		LeetCode 226 Invert Binary Tree
#	Author		Yifei Xie
#	Date		2016.02.02
#	Algorithm	DFS
#	Complexity	Time:O(N)	Space:O(N)
#

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
	def invertTree(self, root):
		"""
		:type root: TreeNode
		:rtype: TreeNode
		"""
		return self.InvertBinaryTree(root)

	def InvertBinaryTree(self, x):
		if x == None:
			return None
		if x.left == None and x.right == None:
			return x

		self.InvertBinaryTree(x.left)
		self.InvertBinaryTree(x.right)
		T = x.left
		x.left = x.right
		x.right = T
		return x
