#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int stringSize = s.size();
        string tmp_s;
        //cout << stringSize << endl;
        vector<bool> isValid(stringSize, false);
        // 我不知道为什么，如果写stringIndex- wordDict[dictIndex].size()值就会溢出 而写成 stringIndex - int(wordDict[dictIndex].size()) 就正确了 
        
        for (int stringIndex = 0; stringIndex<stringSize; stringIndex++){
        	for  (int dictIndex = 0; dictIndex < wordDict.size(); dictIndex++){
        		if (stringIndex - int(wordDict[dictIndex].size()) < -1)
        			continue;
				if (stringIndex - int(wordDict[dictIndex].size()) == -1) {
					tmp_s = s;
					if (tmp_s.substr(0,wordDict[dictIndex].size())==wordDict[dictIndex])
						isValid[stringIndex] = true;		
					continue;
				}
				if (stringIndex - int(wordDict[dictIndex].size()) >= 0) {
					if (isValid[stringIndex - int(wordDict[dictIndex].size())] == false)
						continue;
					tmp_s = s;
					if (tmp_s.substr( stringIndex - int(wordDict[dictIndex].size())+1, int(wordDict[dictIndex].size()) ) == wordDict[dictIndex])
						isValid[stringIndex] = true;
				}
				
			}			
		}
		return isValid[stringSize-1];
    }
};

int main(){
	string s = "leetcode";
	vector<string> wordDict;
	wordDict.push_back("leet");
	wordDict.push_back("code");
	cout << Solution().wordBreak(s, wordDict);
}
