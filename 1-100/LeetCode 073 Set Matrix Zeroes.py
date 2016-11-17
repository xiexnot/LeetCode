#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
    LeetCode 073
    题目： Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
    解法： 暴力
"""

class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if matrix == []:
            return matrix
        m = matrix.__len__()
        n = matrix[0].__len__()
        row = []
        col = []
        for i in range(m):
            row.append(False)
        for j in range(n):
            col.append(False)
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    row[i] = True
                    col[j] = True
        
        for i in range(m):
            for j in range(n):
                if row[i] or col[j]:
                    matrix[i][j] = 0