def ZigZagConversation(s,row):
	result = ""
	if len(s)==0 or row == 1:
		return s
	set_num = int(len(s)) / int(2*row-2)
	if int(len(s)) % int(2*row-2) != 0:
		set_num += 1
			
	for i in range(set_num):
		try:
			target = i*(2*row-2)
			result += s[target]
		except:
			pass
	#print result
	for i in range(1,row-1):
		for k in range(set_num):
			try:
				target = k * (2*row-2) + i
				result += s[target]
			except:
				pass
			try:
				target = (k+1)* (2*row-2) -i
				result += s[target]
			except:
				pass
		#print result
				
	for i in range(set_num):
		try:
			target = i*(2*row-2) + row -1
			result += s[target]
		except:
			pass
	#print result
	return result

class Solution(object):
	
	def convert(self, s, numRows):
		"""
		:type s: str
		:type numRows: int
		:rtype: str
		"""
		return ZigZagConversation(s,numRows)
