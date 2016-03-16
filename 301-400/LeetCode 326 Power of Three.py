import math

class Solution(object):
	def isPowerOfThree(self, n):
		"""
		:type n: int
		:rtype: bool
		"""
		if n <= 0:
			return False
		x = math.log(float(n)) / math.log(3)
		print x - round(x)
		if math.fabs(x - round(x)) < 0.000000000001:
			return True
		else:
			return False 