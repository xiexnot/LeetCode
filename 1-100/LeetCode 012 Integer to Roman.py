class Solution(object):
	def intToRoman(self, num):
		"""
		:type num: int
		:rtype: str
		"""
		result = ""
		num_String = str(num)
		target = len(num_String) - 1
		count_place = 0
		while True:
			if target < 0:
				break
			count_place += 1
			result = self.ConvertRoman(int(num_String[target]),count_place) + result
			target -= 1
		return result
		
	def ConvertRoman(self, x, place):
		value = ""
		if place == 1:
			if x >= 0 and x <=3:
				for i in range(0,x):
					value = value + 'I'
			if x == 4:
				value = "IV"
			if x == 9:
				value = "IX"
			if x >= 5 and x<=8:
				value = "V"
				for i in range(5,x):
					value = value + 'I'	
			
		if place == 2:
			if x >= 0 and x <=3:
				for i in range(0,x):
					value = value + 'X'
			if x == 4:
				value = "XL"
			if x == 9:
				value = "XC"
			if x >= 5 and x<=8:
				value = "L"
				for i in range(5,x):
					value = value + 'X'	
		
		if place == 3:
			if x >= 0 and x <=3:
				for i in range(0,x):
					value = value + 'C'
			if x == 4:
				value = "CD"
			if x == 9:
				value = "CM"
			if x >= 5 and x<=8:
				value = "D"
				for i in range(5,x):
					value = value + 'C'	
			
		if place == 4:
			for i in range(0,x):
				value = value + "M"
		return value