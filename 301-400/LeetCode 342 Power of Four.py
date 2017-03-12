class Solution(object):
	def isPowerOfFour(self, num):
    
            """
            :type num: int
            :rtype: bool
            """
            if (num<0):
                return False
            oddBit = False
            bitCount = 0
            while (num!=0):
                print num," ", num&1
                if oddBit:
                    oddBit = False
                else:
                    oddBit = True
                if (oddBit and num & 1 == 1):
                    print "bit Count + 1"
                    bitCount += 1
                if (oddBit == False and num & 1 == 1):
                    return False
                num = num >> 1
            if (bitCount == 1):
                return True
            return False

print Solution().isPowerOfFour(16)

print Solution().isPowerOfFour(234)
print Solution().isPowerOfFour(256)

