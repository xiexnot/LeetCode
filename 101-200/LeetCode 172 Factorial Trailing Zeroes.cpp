class Solution {
public:
	int trailingZeroes(int n) {
		if (n<0)
			return -1;
		//Reference: http://www.danielbit.com/blog/puzzle/leetcode/leetcode-factorial-trailing-zeroes
		int count = 0;
		for (long i=5;n/i>=1;i*=5)
			count += (n/i);
		return count;
	}
};