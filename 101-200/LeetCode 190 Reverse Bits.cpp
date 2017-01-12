#include <iostream>
#include <string>
#include <stdint.h> 
#include <vector>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> v;
        //	初始化！ 
        //	初始化！
        //	初始化！
        uint32_t new_n = 0;
        uint32_t base = 2;
        cout << n << endl;
        for (int i=0;i<32;i++){
        	v.push_back((n & 1));
        	n = n>>1;
        	cout << n << endl;
        }

        base = 1;
        for (int i=31;i>=0;i--){
        	if (v[i])
        		new_n = new_n + base;
        	cout << v[i];
        	//new_n =  v[i] + (v[i]*base);
        	base *= 2;
        }
        cout << endl;
        return new_n;
    }
};

int main(){
	cout << Solution().reverseBits(43261596) ;
	return 0;
}
