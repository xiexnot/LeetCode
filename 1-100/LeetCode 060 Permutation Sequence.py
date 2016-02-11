class Solution(object):

	def getPermutation(self, n, k):
		"""
		:type n: int
		:type k: int
		:rtype: str
		"""
		Factorial = []
		nums = []
		chosen = []
		for i in range(n):
			chosen.append(False)
			nums.append(-1)
		for i in range(n):
			if i == 0:
				Factorial.append(1)
			else:
				Factorial.append(Factorial[Factorial.__len__()-1]*i)
		return self.kthPermutation(Factorial, nums, chosen, n, k)
		
	def kthPermutation(self, Factorial, nums, chosen, n, k):
		Result = ""
		k = k-1
		for i in range(n)[::-1]:
			nums[i] = k / Factorial[i]
			k = k % Factorial[i]
		print nums
		for i in range(nums.__len__())[::-1]:
			key = nums[i]
			for j in range(chosen.__len__()):
				if chosen[j] == False:
					key -= 1
				if key == -1:
					chosen[j] = True
					Result += str(j+1)
					break
		return Result
