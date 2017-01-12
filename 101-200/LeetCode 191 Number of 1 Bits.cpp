#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n>0){
        	if (n&1)
        		count ++;
        	n = n>>1;
        }
        return count;
    }
};

int main(){
	cout << Solution().hammingWeight(11) << endl;
}
