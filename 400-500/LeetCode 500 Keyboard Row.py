from collections import Counter

class Solution(object):
	def correct(self, x):
		alphabet = []
		for item in x:
			if item in ['Q','W','E','R','T','Y','U','I','O','P','q','w','e','r','t','y','u','i','o','p']:
				alphabet.append(1)
			if item in ['A','S','D','F','G','H','J','K','L','a','s','d','f','g','h','j','k','l']:
				alphabet.append(2)
			if item in ['Z','X','C','V','B','N','M','z','x','c','v','b','n','m']:
				alphabet.append(3)
		if list(Counter(alphabet)).__len__() == 1:
			return True
		else:
			return False

	def findWords(self, words):
		"""
		:type words: List[str]
		:rtype: List[str]
		"""
		CorrectWords = []
		for word in words:
			if self.correct(word):
				CorrectWords.append(word)
		return CorrectWords