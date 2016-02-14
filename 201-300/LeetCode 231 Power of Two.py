# Here the solution from the internet has a f**king brilliant idea to solve it.

class Solution(object):
	def isPowerOfTwo(self, n):
		"""
		:type n: int
		:rtype: bool
		"""
		if n <= 0:
			return False
		x = math.log(float(n)) / math.log(2)
		print x - round(x)
		if math.fabs(x - round(x)) < 0.000000000001:
			return True
		else:
			return False 