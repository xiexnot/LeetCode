#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 069
	题目：	sqrt
	解法：	binary search
"""
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        start = 0
        ending = 100000000
        while start < ending:
            center = (start+ending)/2
            print start," ", ending," ", center
            if center*center <= x and (center+1)*(center+1)>x:
                return center
            if center*center > x:
                ending = center - 1
            else:
                start = center + 1
        return (start+ending)/2
if __name__=="__main__":
	print Solution().mySqrt(5)