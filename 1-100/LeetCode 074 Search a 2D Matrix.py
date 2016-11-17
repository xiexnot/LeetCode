#-*- coding:utf-8 -*-
#!/usr/bin/python
"""
    LeetCode 074
    题目： 找matrix中的元素
    解法： 二分两个维度（加上极大极小行列）
"""
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if matrix == []:
            return False
        if target < matrix[0][0] or target > matrix[matrix.__len__()-1][matrix[0].__len__()-1]:
            return False
        m = matrix.__len__()
        n = matrix[0].__len__()
        matrix.append([matrix[m-1][n-1]+1])
        row_start = 0
        row_ending = matrix.__len__()-1
        row_center = (row_start+row_ending)/2
        while row_start < row_ending:
            if matrix[row_center][0] <= target and matrix[row_center+1][0] > target:
                break
            if matrix[row_center][0] > target:
                row_ending = row_center-1
            else:
                row_start = row_center + 1
            row_center = (row_start+row_ending)/2
        if matrix[row_center][n-1] < target:
            return False
        col_left = 0
        col_right = n-1
        col_center = (col_left+col_right)/2
        while col_left <= col_right:
            if matrix[row_center][col_center] == target:
                return True
            if matrix[row_center][col_center] < target and matrix[row_center][col_center+1] > target:
                return False
            if matrix[row_center][col_center] > target:
                col_right = col_center - 1
            else:
                col_left = col_center + 1
            col_center = (col_left+col_right)/2
        return False
        