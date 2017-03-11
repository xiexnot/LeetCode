import os
import Queue
from collections import Counter

class Solution(object):
    def findPairs(self, nums, k):
        if nums.__len__() == 0:
            return 0
        nums.sort()
        pairCount = 0

        if k == 0:
            numsCounter = Counter(nums)
            numsCounterList = list(numsCounter)
            for uniqueValue in numsCounterList:
                if numsCounter[uniqueValue] > 1:
                    pairCount += 1
            return pairCount

        numsCounter = Counter(nums)
        numsCounterList = list(numsCounter)
        nums = sorted(numsCounterList)

        numsQueue = []
        numsQueue.append(nums[0])
        for index in range(1, nums.__len__()):
            while True:
                if numsQueue.__len__() == 0:
                    break
                if nums[index] - numsQueue[0] < k:
                    break
                if nums[index] - numsQueue[0] == k:
                    pairCount += 1
                    numsQueue = numsQueue[1:]
                    break
                if nums[index] - numsQueue[0] > k:
                    numsQueue = numsQueue[1:]

            numsQueue.append(nums[index])
        return pairCount

print Solution().findPairs([1,2,3,0,1],0)
