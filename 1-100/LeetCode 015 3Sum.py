#-*- coding:utf-8 -*-
#!/usr/bin/python

"""
	LeetCode 015 3Sum
	题目：	对于List而言，找到不同组合的(a,b,c)使得a+b+c=0
	解1：	纯枚举 o(n^3)
	解2：	使用d[sum,i]来统计综合为sum且已经选了i个数字的方案数 然而这种算法sum不定，故空间很难开。如果考虑i<=3时开成多层的hashtable，则效率退化到接近o(n^3)
	解2：	先使得数据有序，枚举第一个数字a,在比他靠后数字中寻找(b,c)使得 b+c = -a。
			而寻找(b,c)使用o(N)的算法，区间首尾各有i j两个pointer a[i] + a[j] 如果a[i] + a[j] 太小 则a[i]向后 否则 a[j]向前
			如果a[i]+a[j]等于需求值，则将i,j平移到新的位置a[k]和a[m] 使得a[i] != a[k] 且 a[m]!=a[j]（因为组合需要数字不同）
			而枚举的第一个数字也保证不一样即可
"""

class Solution(object):
	def threeSum(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[List[int]]
		"""

		nums.sort()
		result = []
		for i in range(nums.__len__()-2):
			if i > 0 and nums[i] == nums[i-1]:
				continue
			target = nums[i] * (-1)
			left = i + 1
			right = nums.__len__()-1
			while left < right:
				if nums[left] + nums[right] == target:
					result.append([nums[i], nums[left], nums[right]])
					while left < right:
						left += 1
						if nums[left] != nums[left-1]:
							break
					while left < right:
						right -= 1
						if nums[right] != nums[right+1]:
							break
				elif nums[left] + nums[right] < target:
					while left < right:
						left += 1
						if nums[left] != nums[left-1]:
							break
				else:
					while left < right:
						right -= 1
						if nums[right] != nums[right+1]:
							break
		return result
