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
			// �������м�������
			// �����middle=(left+right)/2�Ļ� ��left+right��ʱ���Ѿ�����int��
			// ��ʹ�����µķ�ʽ������ 
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
