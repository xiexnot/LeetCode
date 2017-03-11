class Solution(object):
	def reverseVowels(self, s):
            sList = list(s)
            sVowelList = []
            vowelsList = ['A','E','I','O','U','a','e','i','o','u']
            for charIndex in range(sList.__len__()):
                if sList[charIndex] in vowelsList:
                    sVowelList.append(sList[charIndex])
            if sVowelList.__len__() == 0:
                return s
            sVowelListIndex = sVowelList.__len__()-1
            for charIndex in range(sList.__len__()):
                if sList[charIndex] in vowelsList:
                    sList[charIndex] = sVowelList[sVowelListIndex]
                    sVowelListIndex -= 1
            return ''.join(sList)
