#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
	LeetCode 064
	题目：	矩阵 最小路径之和
	解法：	DP
"""

class Solution(object):
    def min(self, a,b):
        if a>b:
            return b
        return a
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if grid.__len__() == 0:
            return 0
            
        result = []
        for i in range(grid.__len__()):
            result_item = []
            for j in range(grid[i].__len__()):
                result_item.append(50000000)
            result.append(result_item)
            
        result[0][0] = grid[0][0]
        for i in range(result.__len__()):
            for j in range(result[i].__len__()):
                if i-1>=0:
                    result[i][j] = Solution().min(result[i][j], result[i-1][j]+grid[i][j])
                if j-1>=0:
                    result[i][j] = Solution().min(result[i][j], result[i][j-1]+grid[i][j])
        return result[grid.__len__()-1][grid[0].__len__()-1]
        