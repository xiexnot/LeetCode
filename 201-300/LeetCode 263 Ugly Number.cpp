class Solution {
public:
	bool isUgly(int num) {
		if (num==1)
			return true;
			
		if (num<=0)
		    return false;

		while (num % 2 == 0)
			num = num/2;
		cout << num;
		if (num==1)
			return true;

		while (num%5 == 0)
			num = num/5;
		if (num==1)
			return true;

		while (num%3 == 0)
			num = num/3;
		if (num==1)
			return true;

		return false;		
	}
};