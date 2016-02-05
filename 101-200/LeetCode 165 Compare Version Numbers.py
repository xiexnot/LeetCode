class Solution(object):
	def compareVersion(self, version1, version2):
		"""
		:type version1: str
		:type version2: str
		:rtype: int
		"""
		value1 = version1.split('.')
		value2 = version2.split('.')
		len1 = len(value1)
		len2 = len(value2)
		for i in range(len1):
			value1[i] = int(value1[i])
		for i in range(len2):
			value2[i] = int(value2[i])
		while True:
			if len1 == 1:
				break
			if value1[len1-1] == 0:
				len1 -= 1
				value1 = value1[:-1]
			else:
				break
		while True:
			if len2 == 1:
				break
			if value2[len2-1] == 0:
				len2 -= 1
				value2 = value2[:-1]
			else:
				break
		for i in range(min(len1,len2)):
			if value1[i] < value2[i]:
				return -1
			if value1[i] > value2[i]:
				return 1
		if len1 == len2:
			return 0
		if len1 < len2:
			return -1
		return 1
