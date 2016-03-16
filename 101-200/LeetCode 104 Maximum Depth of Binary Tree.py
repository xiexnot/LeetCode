#
#	Project		LeetCode 104 Maximum Depth of Binary Tree
#	Author		Yifei Xie
#	Date		2016.02.02
#	Algorithm
#	Complexity	Time:O(N)	Space:O(N)
#

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
	def maxDepth(self, root):
		"""
		:type root: TreeNode
		:rtype: int
		"""
		return self.FindDepth(root)

	def FindDepth(self, x):
		if x == None:
			return 0
		if x.left == None and x.right == None:
			return 1
		return 1 + max(self.FindDepth(x.left), self.FindDepth(x.right))
