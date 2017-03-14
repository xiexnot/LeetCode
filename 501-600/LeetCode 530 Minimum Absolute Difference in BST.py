# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

#	不知道哪里出问题
#	本地调试没问题
#	提交到云端的时候 测试有问题

class Solution(object):
	valueList = []

	def getValue(self, x):
		if x == None:
			return 0
		Solution().valueList.append(x.val)
		if x.left!=None:
			self.getValue(x.left)
		if x.right!=None:
			self.getValue(x.right)
		return 0

	def getMinimumDifference(self, root):
		"""
		:type root: TreeNode
		:rtype: int
		"""
		if root!=None:
			self.getValue(root)
		Solution().valueList.sort()
		
		print Solution().valueList
		if Solution().valueList.__len__() == 0 :
			return 0
		minDifference = 20000000
		for i in range(1, Solution().valueList.__len__()):
			minDifference = min(minDifference, Solution().valueList[i] - Solution().valueList[i-1])
		return minDifference
