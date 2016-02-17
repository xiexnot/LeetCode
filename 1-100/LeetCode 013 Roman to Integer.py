class Solution(object):
	def romanToInt(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		result = 0
		num = []
		place = 0
		for i in range(len(s)):
			num.append(self.convertToInt(s[i]))
		for i in range(len(s)-1):
			if num[i] < num[i+1]:
				result -= num[i]
			else:
				result += num[i]
		result += num[len(s)-1]
		return result
		
	def convertToInt(self, x):
		if x == 'M':
			return 1000
		if x == 'D':
			return 500
		if x == 'C':
			return 100
		if x == 'L':
			return 50
		if x == 'X':
			return 10
		if x == 'V':
			return 5
		if x == 'I':
			return 1
		return 0