class Solution(object):
	def reverse(self, x):
		"""
		:type x: int
		:rtype: int
		"""
		x_string = str(x)
		result = ""
		if x_string[0]=="-":
			result = "-"
			for i in range(len(x_string)-1):
				result += x_string[len(x_string)-i-1]
		else:
			for i in range(len(x_string)):
				result += x_string[len(x_string)-i-1]
		if abs(int(result))>2147483648:
			return 0
		return int(result)