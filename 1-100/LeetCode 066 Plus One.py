class Solution(object):
	def plusOne(self, digits):
		"""
		:type digits: List[int]
		:rtype: List[int]
		"""
		digits[digits.__len__()-1] += 1
		for i in range(1,digits.__len__())[::-1]:
			if digits[i] >= 10:
			#	print i
				digits[i-1] += 1
				digits[i] = 0
		print digits
		if digits[0] >= 10:
			digits.append(0)
			digits[0] = 0
			for i in range(0,digits.__len__()-1):
				digits[i+1] = digits[i]
			digits[0] = 1
			
		return digits