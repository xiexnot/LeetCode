class Solution(object):
	def maxArea(self, height):
		"""
		:type height: List[int]
		:rtype: int
		"""
		height_forwardplace = []
		height_backwardplace = []
		print height
		print height[0]
		for i in range(len(height)):
			height_forwardplace.append([height[i],i])
			height_backwardplace.append([height[i],(len(height)-1)-i])
		
		height_forwardplace.sort()
		height_backwardplace.sort()
		
		left = []
		right = []
		
		for i in range(len(height)):
			left.append(i)
			right.append(i)
		
		for i in range(len(height_forwardplace)):
			target = i
			while True:
				if target < 0:
					break
				if height_forwardplace[target][0] < height_forwardplace[i][0] and height_forwardplace[target][1] < height_forwardplace[i][1]:	
					print "target = ",target," i = ",i
					break
				target -= 1
			if target != -1:
				left[height_forwardplace[i][1]] = height_forwardplace[target][1]
			else:
				left[height_forwardplace[i][1]] = -1
		
		for i in range(len(height_backwardplace)):
			height_backwardplace[i][1] = len(height) - 1 - height_backwardplace[i][1]
		
		for i in range(len(height_backwardplace)):
			target = i
			while True:
				if target < 0:
					break
				if height_backwardplace[target][0] < height_backwardplace[i][0] and height_backwardplace[target][1] > height_backwardplace[i][1]:
					print "target = ",target," i = ",i
					break
				target -= 1
			if target != -1:
				right[height_backwardplace[i][1]] = height_backwardplace[target][1]
			else:
				right[height_backwardplace[i][1]] = len(height_backwardplace)
		
		print "left = ",left
		print "right  = ",right	
		print height_forwardplace
		print height_backwardplace
		
		return 0 
if __name__ == "__main__":
	print Solution().maxArea([5,1,2,3,2,1])  
		