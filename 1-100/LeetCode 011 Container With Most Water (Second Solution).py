#-*- coding:utf-8 -*-
#!/usr/bin/python

"""
	LeetCode 011
	题目：	在已有的List中 寻找min(a[i]-a[j])*(j-i)的最大值
	解1：	O(N^2)的算法，枚举a[i]和a[j]进行计算
	解2：	从a[1]和a[N]开始作为初始计算值考察a[i]和a[j]，如果a[1]<a[N]则之后考察a[2]和a[N] （在j-i变小的情况下，我们希望找到较大的a[i]依次弥补。而如果我们移动j而寻找a[j]，则在计算的时候min(a[i],a[j])必然小于a[i]，则解必定不优）
"""

def max(a,b):
	if a > b:
		return a
	return b

def min(a,b):
	if a < b:
		return a
	return b

class Solution(object):
	def maxArea(self, height):
		"""
		:type height: List[int]
		:rtype: int
		"""
		result = 0
		i = 0
		j = height.__len__()-1
		while True:
			if i >= j:
				break
			result = max(result, min(height[i],height[j]) * (j-i))
			if height[i] < height[j]:
				i += 1
			else:
				j -= 1
		return result
		
if __name__ == "__main__":
	Solution().maxArea([1,2,1])