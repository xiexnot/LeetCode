#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

class Solution {
	
private:
	bool isValid(string x){
		int intx = stoi(x);
		if (intx < 0 || intx > 255)
			return false;
		if (x.length() != to_string(intx).length()){
			return false;
		}
		return true; 
	}
	
private:
	bool isExist(vector<string> &IpAddresses, string& newString){
		for (int vectorItem=0;vectorItem<IpAddresses.size(); vectorItem++)
			if (IpAddresses[vectorItem] == newString)
				return true;
		return false;
	}
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> IpLength(4,0);
        vector<string> IpAddresses; 
        string string1, string2, string3, string4, newString;
		int stringSize = s.size();
		int len4;
		for (int len1 = 1;len1<4;len1++)
			for (int len2 = 1; len2<4; len2++)
				for (int len3 = 1; len3<4; len3++)
				{
					len4 = stringSize - len1 - len2 - len3;
					if (len4 < 1 || len4 > 3)
						continue;
					string1 = s.substr(0,len1);
					string2 = s.substr(0+len1,len2);
					string3 = s.substr(0+len1+len2, len3);
					string4 = s.substr(0+len1+len2+len3, len4);
					if (isValid(string1) && isValid(string2) && isValid(string3) && isValid(string4)){
						//newString = string1 + "." + string2 + "." + string3 + "." + string4;
						newString = to_string(stoi(string1)) + "." + to_string(stoi(string2)) + "." + to_string(stoi(string3)) + "." + to_string(stoi(string4));
						if (isExist(IpAddresses, newString) == false)
							IpAddresses.push_back(newString);
					}					
				}
			
		return IpAddresses;
						
    }
};

int main(){
	
}
