# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

CurrentDepth = 0 
NodeDepth = -1
Node = None

class Solution:
	# @param root, a tree link node
	# @return nothing
	def connect(self, root):
		global CurrentDepth, Node, NodeDepth
		if (root is None or (root.left is None and root.right is None)):
			return
		