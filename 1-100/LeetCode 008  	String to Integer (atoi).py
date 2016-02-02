class Solution(object):
			
	def myAtoi(self, str):
		"""
		:type str: str
		:rtype: int
		"""
		INT_MAX = 2147483647
		INT_MIN = -2147483648		
		
		result = 0
		if str == "":
			return 0
		while True:
			if str[0] != ' ':
				break
			str = str[1:]
		
		positive_flag = 0
		negtive_flag = 0
		for i in range(len(str)):
			if str[i] == '-':
				negtive_flag += 1
			if str[i] == '+':
				positive_flag += 1
		if negtive_flag + positive_flag > 1:
			return 0
		if positive_flag == 0 and negtive_flag == 0:
			positive_flag = 1
		if str[0] == '+' or str[0] == '-':
			str = str[1:]
		
		for i in range(len(str)):
			if (ord('0') > ord(str[i]) or ord('9') < ord(str[i])):
				break
			if ord('0') <= ord(str[i]) and ord(str[i]) <= ord('9'):
				result = result * 10 + ord(str[i]) - ord('0')
				
		if negtive_flag == 1:
			result = result * (-1)

		if result > INT_MAX:
			result = INT_MAX
		if result < INT_MIN:
			result = INT_MIN 
		return result
		
if __name__ == "__main__":
    print Solution().myAtoi("") 
    print Solution().myAtoi("-1")
    print Solution().myAtoi("2147483647") 
    print Solution().myAtoi("2147483648") 
    print Solution().myAtoi("-2147483648")  
    print Solution().myAtoi("-2147483649")  