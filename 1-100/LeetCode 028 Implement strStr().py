#
#	Project		LeetCode 028 Implement strStr()
#	Author		Yifei Xie
#	Date		2016.01.25
#	Algorithm	force comparasion
#	Complexity	Time:O(N^2)	Space:O(N) 
#

class Solution(object):
	def strStr(self, haystack, needle):
		"""
		:type haystack: str
		:type needle: str
		:rtype: int
		"""
		if len(needle) == 0:
			return 0
		if len(needle) !=0 and len(haystack) == 0:
			return -1
		haystack_point = 0
		haystack_lengh = len(haystack)
		needle_point = 0
		needle_length = len(needle)
		success = False
		for i in range(haystack_lengh - needle_length+ 1):
			if haystack[i] == needle[0]:
				for j in range(needle_length):
					if i+j >= haystack_lengh:
						break
					if haystack[i+j] != needle[j]:
						break
					if j == needle_length - 1 and haystack[i+j] == needle[j]:
						success = True
						return i
		return -1