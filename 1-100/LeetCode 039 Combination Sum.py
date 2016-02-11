class Solution(object):
	def combinationSum(self, candidates, target):
		"""
		:type candidates: List[int]
		:type target: int
		:rtype: List[List[int]]
		"""
		candidates = sorted(candidates)
		Stack = []
		global Result_Combination
		Result_Combination = []
		for i in range(target / candidates[0] + 1):
			Stack.append(-1)
		self.DFS(0, 0, Stack, candidates, target)
		return Result_Combination
	
	def DFS(self, item, last_value, Stack, candidates, target):
		#print "item = ",item, " target = ", target
		if target < 0:
			return 0
		if target == 0:
			#find a combinationSum
		#	print "Find Combination..."
			Result = []
			for i in range(item):
				Result.append(Stack[i])
			Result_Combination.append(Result)
			return 0
		for i in range(last_value, len(candidates)):
			Stack[item] = candidates[i]
			self.DFS(item+1, i, Stack, candidates, target - candidates[i])
		Stack[item] = -1
		return 0