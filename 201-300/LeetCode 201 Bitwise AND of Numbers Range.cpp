class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		// reference: http://www.cnblogs.com/grandyang/p/4431646.html
		// 二进制下的m和n 左边公共的1部分的长度
		int base;
		int count = 0;
		int digit1, digit2;
		int startIndex=-1;
		for (int i=31;i>=0;i--){
			base = pow(2,i);
			//cout << (base & m) << " " << (base & n) << " "<<base<< endl;
			digit1 = base & m;
			digit2 = base & n;
			//cout << digit1 << " " << digit2 << " " << base << endl;
			if (digit1!=digit2)
				//digit1 !=digit2
				return 0;
			if (digit1 && digit1==digit2){
				startIndex = i;
				break;
			}

		}
		if (startIndex==-1)
			return count;
		for (int i=startIndex;i>=0;i--){
		    base = pow(2,i);
			digit1 = base & m;
			digit2 = base & n;
			if (digit1!=digit2)
				//digit1 !=digit2
			    break;
			else
				count += ((digit1) ? base:0);
		}
		return count;
	}
};