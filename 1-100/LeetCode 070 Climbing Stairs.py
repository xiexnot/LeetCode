#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 070
	题目：	爬梯子
	解法：	DP
"""

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = []
        for i in range(n+1):
            res.append(0)
        res[0]=1
        res[1]=1
        if n <=1 :
            return res[n]
        for i in range(2,n+1):
            res[i] += (res[i-1]+res[i-2])
        return res[n]
        