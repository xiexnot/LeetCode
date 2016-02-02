#
#	Project		LeetCode 038 Count and Say
#	Author		Yifei Xie
#	Date		2016.02.02
#	Algorithm	force interation
#	Complexity	Time:O(N)	Space:O(N)
#
class Solution(object):
	def countAndSay(self, n):
		"""
		:type n: int
		:rtype: str
		"""
		if n == 0:
			return ""
		value = "1"
		for i in range(2,n+1):
			value = self.getCountAndSay(value)
		return value

	def getCountAndSay(self, x):
		result = ""
		i = 0
		while True:
			if i >= len(x):
				break
			j = i
			while True:
				if j >= len(x):
					j -= 1
					break
				if x[i] != x[j]:
					j -= 1
					break
				j += 1
			result = result + str(j-i+1)+ str(x[i])
			i = j + 1
		return result

if __name__ == "__main__":
	print Solution().countAndSay(2)
	print Solution().countAndSay(3)
	print Solution().countAndSay(4)
