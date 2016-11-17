#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
    LeetCode 075
    题目： 排序
    解法： bubble sort
"""

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = nums.__len__()
        for i in range(n):
            for j in range(i+1,n):
                if nums[i] > nums[j]:
                    p = nums[i]
                    nums[i] = nums[j]
                    nums[j] = p
        
        