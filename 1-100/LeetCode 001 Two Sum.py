class Solution(object):
    def twoSum(self, num, target):
        tmp = {}
        for i in range(len(num)):
            if target - num[i] in tmp:
                return(tmp[target - num[i]] +1, i + 1)
            else:
                tmp[num[i]] = i;