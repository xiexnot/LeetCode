#
#	Project		LeetCode 292 Nim Game
#	Author		Yifei Xie
#	Date		2016.02.02
#	Algorithm	Simple Game Theory
#	Complexity	Time:O(1)	Space:O(1)
#

class Solution(object):
	def canWinNim(self, n):
		"""
		:type n: int
		:rtype: bool
		"""
		if n < 4:
			return True
		if n % 4 == 0:
			return False
		return True

if __name__ == "__main__":
	print Solution().canWinNim(2)
