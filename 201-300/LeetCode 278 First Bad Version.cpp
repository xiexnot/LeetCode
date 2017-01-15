// Forward declaration of isBadVersion API.

#include <iostream>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int left = 1;
		int right = n;
		if (isBadVersion(left))
			return left;
		int middle;
		while (left<right){
			// 本题中有极限数据
			// 如果用middle=(left+right)/2的话 在left+right的时候已经超过int了
			// 故使用以下的方式来计算 
			middle = (right-left)/2 + left;
			if (isBadVersion(middle))
				right = middle;
			else
				left = middle + 1;

		}
		return left;
	}
};

int main(){
	cout << Solution().firstBadVersion(2126753390);
}
