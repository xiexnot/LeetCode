class Solution(object):
	def combinationSum2(self, candidates, target):
		"""
		:type candidates: List[int]
		:type target: int
		:rtype: List[List[int]]
		"""
		candidates = sorted(candidates)
		Stack = []
		chosen = []
		for i in range(len(candidates)):
			chosen.append(False)
		global Result
		Result = []
		for i in range(target/candidates[0]+1):
			Stack.append(-1)
		self.DFS(0, -1, Stack, candidates, chosen, target)
		return Result
		
	def DFS(self, item, last_value, Stack, candidates , chosen, target):
		continue_flag = False
		if target < 0:
			return 0
		if target == 0:
			result_combination = []
			for i in range(item):
				result_combination.append(Stack[i])
			Result.append(result_combination)
			return 0
		for i in range(last_value+1, len(candidates)):
			try:
				continue_flag = False
				x = i-1
				while True:
					if x < 0:
						break
					if candidates[x] == candidates[i] and chosen[x] == False:
						continue_flag = True
						break
					if candidates[x] != candidates[i]:
						break
					x -= 1
				if continue_flag == True:
					continue
			except:
				pass
			Stack[item] = candidates[i]
			chosen[i] = True
			self.DFS(item+1, i, Stack, candidates, chosen, target - Stack[item])
			chosen[i] = False
		Stack[item] = -1
		
		return 0