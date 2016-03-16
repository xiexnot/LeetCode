class Solution(object):
	def longestCommonPrefix(self, strs):
		"""
		:type strs: List[str]
		:rtype: str
		"""
		
		LongestCommonPrefix = ""
		
		if len(strs) == 0:
			return LongestCommonPrefix
		MIN_LENGTH = len(strs[0])
		for i in range(len(strs)):
			if MIN_LENGTH > len(strs[i]):
				MIN_LENGTH = len(strs[i])

		if MIN_LENGTH == 0:
			return LongestCommonPrefix
			
		for i in range(MIN_LENGTH):
			LongestCommonPrefix = LongestCommonPrefix + strs[0][i]
			for j in range(len(strs)):
				if self.CommonPrefix(LongestCommonPrefix,strs[j]) == False:
					LongestCommonPrefix = LongestCommonPrefix[:-1]
					return LongestCommonPrefix
		
		return LongestCommonPrefix
		
	def CommonPrefix(self, Prefix, string_x):
		for i in range(len(Prefix)):
			if Prefix[i] != string_x[i]:
				return False
		return True