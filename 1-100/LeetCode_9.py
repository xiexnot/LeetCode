class Solution(object):
	def isPalindrome(self, x):
		"""
		:type x: int
		:rtype: bool
		"""
		x_String = str(x)
		if x<0:
			return False
		for i in range(len(x_String)):
			if x_String[i] != x_String[len(x_String)-i-1]:
				return False
		return True	