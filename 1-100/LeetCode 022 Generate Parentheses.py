class Solution(object):
	def generateParenthesis(self, n):
		"""
		:type n: int
		:rtype: List[str]
		"""
		global Result
		Result = []
		Stack = []
		for i in range(2*n+1):
			Stack.append(0)
		self.DFS(0,0,0, Stack, n)
		return Result
		
	def DFS(self, item, left, right, Stack, n):
		if right < left or left > n or right > n:
			return 0
		if left == right and left + right == 2*n:
			print 
			result_combination = ""
			for i in range(item):
				if Stack[i] == 1:
					result_combination = result_combination+ ')'
				if Stack[i] == -1:
					result_combination = result_combination+ '('
			Result.append(result_combination)
			return 0
		#print item
		Stack[item] = 1
		self.DFS(item+1, left+1, right, Stack, n)
		Stack[item] = -1
		self.DFS(item+1, left, right+1, Stack, n)
		Stack[item] = 0
		return 0
	