class Solution(object):
	def lengthOfLastWord(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		result = 0
		while True:
			if s == "":
				break
			if s[len(s)-1] != " ":
				break
			s = s[:-1]
		if len(s) == 0:
			return result
		x = len(s) - 1
		while True:
			if x < 0:
				break
			if s[x] != " ":
				result += 1
			else:
				break
			x -= 1
		return result