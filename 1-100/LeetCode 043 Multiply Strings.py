#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 043
	题目：	高精度乘法
	解法：	暴力
	注意：	1. 对于9999*0时 最后等于的string是0000 要删除到只剩下1个0
			2. 现在的写法 能对但不太优美 就这样
"""

def max(a,b):
	if a>b:
		return a
	return b

class Solution(object):

	def inverse_str(self, num):
		result = ""
		for item in num:
			result = item + result
		return result

	def add(self, num1, num2):
		num1 = Solution().inverse_str(num1)
		num2 = Solution().inverse_str(num2)
		num1 = list(num1)
		num2 = list(num2)
		result = []

		for i in range(1+max(num1.__len__(), num2.__len__())):
			result.append(0)

		for i in range(num1.__len__()):
			result[i] = result[i] + int(num1[i])
			result[i+1] += (result[i] / 10)
			result[i] %= 10

		for i in range(num2.__len__()):
			result[i] = result[i] + int(num2[i])
			result[i+1] += (result[i] / 10)
			result[i] %= 10

		result_str = ""
		for item in result:
			result_str = result_str + str(item)
		result_str = Solution().inverse_str(result_str)
		while result_str.__len__() > 1 and result_str[0] == "0":
			result_str = result_str[1:]
		return result_str
		

	def multiply_single_digit(self, num1, digit):
		digit = int(digit)
		num1 = Solution().inverse_str(num1)
		num1 = list(num1)
		result = []
		for i in range(num1.__len__()+1):
			result.append(0)
		for i in range(num1.__len__()):
			result[i] = result[i] + digit * int(num1[i])
			if result[i] >= 10:
				result[i+1] += (result[i] / 10)
				result[i] %= 10
		#print result[i]
		result_str = ""
		for i in range(result.__len__()):
			result_str = result_str + str(result[i])
		result_str = Solution().inverse_str(result_str)
		while result_str.__len__() > 1 and result_str[0] == "0":
			result_str = result_str[1:]
		#print " ",result_str
		return result_str

	def multiply(self, num1, num2):
		"""
		:type num1: str
		:type num2: str
		:rtype: str
		"""

		result = "0"
		base = 0
		i = num2.__len__()-1
		while i>=0:
			multiply_digit_result = Solution().multiply_single_digit(num1, num2[i])
			#print multiply_digit_result
			for k in range(base):
				multiply_digit_result = multiply_digit_result + "0"
			result = Solution().add(result, multiply_digit_result)
			i -= 1
			base += 1

		return result

if __name__=="__main__":
	print Solution().multiply("9999","0")
	print Solution().multiply_single_digit("22","7")