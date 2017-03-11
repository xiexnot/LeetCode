class Solution(object):
	def reverseString(self, s):
            stringLength = s.__len__()
            stringList = list(s)
            for charIndex in range(stringLength/2):
                tmp = stringList[charIndex]
                stringList[charIndex] = stringList[stringLength - charIndex - 1]
                stringList[stringLength - charIndex - 1] = tmp
            return ''.join(stringList)
