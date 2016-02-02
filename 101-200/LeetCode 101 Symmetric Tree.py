# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Sequence(object):
	def __init__(self):
		self.front_ordering = []
		self.middle_ordering = []
		self.back_ordering = []

class Solution(object):
	def isSymmetric(self, root):
		"""
		:type root: TreeNode
		:rtype: bool
		"""
		P = Sequence()
		self.Front_Search(P, root)
		self.Middle_Search(P, root)
		self.Back_Search(P, root)
		Q = Sequence()
		self.InverseBinaryTree(root)
		self.Front_Search(Q, root)
		self.Middle_Search(Q, root)
		self.Back_Search(Q, root)
		if self.CheckSameTree(P,Q) == True:
			return True
		else:
			return False
	def InverseBinaryTree(self, x):
		if x == None:
			return 0
		self.InverseBinaryTree(x.left)
		self.InverseBinaryTree(x.right)
		tmp = x.left
		x.left = x.right
		x.right = tmp
		return 0
	def Front_Search(self, X, x):
		if x == None:
			X.front_ordering.append(None)
			return 0
		X.front_ordering.append(x.val)
		self.Front_Search(X, x.left)
		self.Front_Search(X, x.right)
		return 0

	def Back_Search(self, X, x):
		if x == None:
			X.back_ordering.append(None)
			return 0
		self.Back_Search(X, x.left)
		self.Back_Search(X, x.right)
		X.back_ordering.append(x.val)
		return 0
	def Middle_Search(self, X, x):
		if x == None:
			X.middle_ordering.append(None)
			return 0
		self.Middle_Search(X, x.left)
		X.middle_ordering.append(x.val)
		self.Middle_Search(X, x.right)
		return 0

	def CheckSameTree(self, P, Q):
		if len(P.front_ordering) != len(Q.front_ordering):
			return False
		if len(P.middle_ordering) != len(Q.middle_ordering):
			return False
		if len(P.back_ordering) != len(Q.back_ordering):
			return False
		for i in range(len(P.front_ordering)):
			if P.front_ordering[i] != Q.front_ordering[i]:
				return False
		for i in range(len(P.middle_ordering)):
			if P.middle_ordering[i] != Q.middle_ordering[i]:
				return False
		for i in range(len(P.back_ordering)):
			if P.back_ordering[i] != Q.back_ordering[i]:
				return False
		return True
