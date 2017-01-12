class Solution {
private:
	map<int,bool> hash;
	map<int,bool>::iterator it;
private:
	int decodedChar(char x){
		switch (x){
			case 'A':
				return 0;
			case 'T':
				return 1;
			case 'C':
				return 2;
			case 'G':
				return 3;
		}
		return 0;
	}
private:
	int decodedString(string &s, int x, int y){
		int decodedStringResult = 0;
		for (int i=x;i<=y;i++){
			decodedStringResult = decodedStringResult * 4 + decodedChar(s[i]);
		}
		return decodedStringResult;
	}
private:
	bool isExist(vector<string> &vec, string &target){
		if (vec.empty())
			return false;
		for (int i=0;i<vec.size();i++)
			if (vec[i]==target)
				return true;
		return false;
	}
public:
    vector<string> findRepeatedDnaSequences(string s) {
  		int sSize = s.size();
  		int leftIndex, rightIndex;
  		int decodedSubstr;
  		vector<string> repeatedDnaSequences;
  		string newDnaSequence;

  		for (int i=9;i<sSize;i++){
  			leftIndex = i - 10 + 1;
  			rightIndex = i;
  			decodedSubstr = decodedString(s, leftIndex, rightIndex);
  			//	if decodedSubstr exists
  			//	vector<string>++
  			//	else dictionary.append()
  			it = hash.find(decodedSubstr);
  			if (it != hash.end()){
  				//find it successfully
  				newDnaSequence = s.substr(leftIndex, 10);
  				//	需要防止同样的内容被加入repeatedDnaSequences多次
  				if (isExist(repeatedDnaSequences, newDnaSequence)==false)
  					repeatedDnaSequences.push_back(newDnaSequence);	
  			}
  			else{
  				hash[decodedSubstr] = true;
  			}
  		}
  		return repeatedDnaSequences;
    }
};