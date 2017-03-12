class Solution(object):
    def convertToBase7(self, num):
        numString = ""
        bit = 1
        if (num<0):
            num = (-1)*num
            bit = -1
        if (num==0):
            return "0"
        while (num>0):
            numString = str(num%7) + numString
            num = num / 7
        if bit == -1:
            return "-" + numString
        else:
            return numString

