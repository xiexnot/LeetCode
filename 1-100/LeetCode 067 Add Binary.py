#
#	Project		LeetCode 067 Add Binary
#	Author		Yifei Xie
#	Date		2016.02.02
#	Algorithm
#	Complexity	Time:O(N)	Space:O(N)
#

class Number(object):
	def __init__(self):
		self.value = []
		self.len = 0

class Solution(object):
	def addBinary(self, a, b):
		"""
		:type a: str
		:type b: str
		:rtype: str
		"""
		A = Number()
		B = Number()
		A.len = len(a)
		B.len = len(b)
		for i in range(A.len):
			A.value.append(int(a[A.len-i-1]))
		for i in range(B.len):
			B.value.append(int(b[B.len-i-1]))
		C = Number()
		C.len = max(A.len,B.len)
		for i in range(C.len+1):
			C.value.append(0)
		for i in range(C.len):
			try:
				C.value[i] = C.value[i] + A.value[i]
			except:
				pass
			try:
				C.value[i] = C.value[i] + B.value[i]
			except:
				pass
			if C.value[i] >= 2:
				C.value[i+1] += C.value[i] / 2
				C.value[i] = C.value[i] % 2
		if C.value[C.len] == 0:
			C.value = C.value[:-1]
		else:
			C.len = len(C.value)

		result = ""
		for i in range(C.len):
			result += str(C.value[C.len-i-1])
		return result
