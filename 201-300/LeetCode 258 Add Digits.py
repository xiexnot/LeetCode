#
#	Project		LeetCode 292 Nim Game
#	Author		Yifei Xie
#	Date		2016.02.02
#	Algorithm	Simple Game Theory
#	Complexity	Time:O(1)	Space:O(1)
#

class Solution(object):
	def addDigits(self, num):
		"""
		:type num: int
		:rtype: int
		"""
		value = str(num)
		while True:
			if len(value) == 1:
				break
			digit_sum = 0
			for i in range(len(value)):
				digit_sum += int(value[i])
			value = str(digit_sum)
		return int(value)

if __name__ == "__main__":
	print Solution().addDigits(456)
