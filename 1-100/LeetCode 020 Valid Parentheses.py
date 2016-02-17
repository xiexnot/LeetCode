class Solution(object):
	def isValid(self, s):
		"""
		:type s: str
		:rtype: bool
		"""
		stack = []
		for i in range(len(s)):
			stack.append("")
		top = 0
		for i in range(len(s)):
			if self.FrontSymbol(s[i]) == True:
				stack[top] = s[i]
				top += 1
			else:
				if top == 0: # when Right Symbol enters, the stack is empty
					return False
				if self.isMatch(s[i],stack[top-1])==True:
					stack[top-1] == ""
					top -= 1
				else:
					return False
		if top != 0:
			return False
			
		return True
		
		
	def isMatch(self, x, y):
		if x == ')' and y == '(':
			return True
		if x == ']' and y == '[':
			return True
		if x == '}' and y == '{':
			return True
		return False
		
	def FrontSymbol(self, x):
		if x == '(' or x == '[' or x == '{':
			return True
		return False
		