class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> subString;
		map<char, string> hash;
		map<string, char> hash2;
		string current_string;

		// 从char->string和string->char 分别建立与维护hash

		while (true){
			if (str.find_first_of(' ')!=std::string::npos){
				current_string = str.substr(0, str.find_first_of(' '));
				str.erase(0, str.find_first_of(' ')+1);
				subString.push_back(current_string);
			}
			else{
				current_string = str;
				subString.push_back(current_string);
				break;
			}
		}

		for (int i=0;i<subString.size();i++){

			if (hash.find(pattern[i]) != hash.end() ){
				if (hash[pattern[i]] != subString[i])
					return false;
			}
			else
				hash[pattern[i]] = subString[i];

			if (hash2.find(subString[i]) != hash2.end()){
				if (hash2[subString[i]] != pattern[i])
					return false;
			}
			else
				hash2[subString[i]] = pattern[i];
		}
		return (pattern.size()==subString.size()?true:false);
	}
};