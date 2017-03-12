#include <string>
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

class Solution{
	public:
		string reverseStr(string s, int k){
			int startKey, endKey, stringLength;
			char tmp;
			startKey = 0;
			stringLength = s.size();
			while (1){
				if (startKey >= stringLength){
					break;
				}
				endKey = startKey + k - 1;
				if (endKey >= stringLength){
					endKey = stringLength - 1;
				}
				cout << startKey << " " << endKey << endl;
				for (int i=0; i<(endKey-startKey+1)/2 ;i++){
					tmp = s[i + startKey];
					s[i+startKey] = s[endKey-i];
					s[endKey-i] = tmp;
				}

				startKey = startKey + (k * 2);

			}
			return s;
		}
};
