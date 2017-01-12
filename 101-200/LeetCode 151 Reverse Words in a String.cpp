#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
	void convertString(string &s, int topIndex, int tailIndex) {
		char tmpChar;
		while (topIndex<tailIndex){
			tmpChar = s[topIndex];
			s[topIndex] = s[tailIndex];
			s[tailIndex] = tmpChar;
			topIndex ++;
			tailIndex --;
		}
		
	}
public:
	void reverseWords(string &s) {
		char tmpChar;
		//	reverse
		for (int i=0;i<s.size()/2;i++){
			tmpChar = s[i];
			s[i] = s[s.size()-1-i];
			s[s.size()-1-i] = tmpChar;
		}
		
		//	delete multiple space in begining and ending
		while (!s.empty() && s[0]==' ')
			s.erase(0,1);
		while (!s.empty() && s[s.size()-1]==' ')
			s.erase(s.size()-1,1);
		if (s.empty())
			return ;
			
		// delete multiple space between the words
		int charIndex = 0;
		int currentStringSize = s.size();
		while (charIndex<currentStringSize){
			if (s[charIndex] == ' ' && s[charIndex-1] == ' '){
				//delete after space
				s.erase(charIndex,1);
				currentStringSize --; 
			} 
			else
				charIndex ++;	
		}
		
		//	reverse each single word
		int topIndex, tailIndex;
		topIndex = 0;
		for (int i=0;i<s.size();i++)
			if (s[i] == ' '){
				tailIndex = i-1;
				//cout << topIndex << " " <<  tailIndex << endl;
				convertString(s, topIndex, tailIndex);
				topIndex = i+1;
			}
		if (topIndex>=0 && topIndex<s.size()){
			tailIndex = s.size()-1;
			convertString(s, topIndex, tailIndex);
		}
	}
};

int main(){
	string s="   the            sky          is            blue   "; 
	//cout << s << endl;
	Solution().reverseWords(s);
	cout << s << endl;
	return 0;
}
