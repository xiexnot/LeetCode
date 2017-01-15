class Solution {
public:
	bool isAnagram(string s, string t) {

		// 用map当hash table 统计s和t中各个字母的出现频率
		
		if (s.size()!=t.size()) 
			return false;
		map<char,int> hash;
		for (int i=0;i<s.size();i++)
			if (hash.find(s[i])!=hash.end())
				hash[s[i]] = hash[s[i]] + 1;
			else
				hash[s[i]] = 1;

		for (int i=0;i<t.size();i++){
			if (hash.find(t[i]) != hash.end()){
				hash[t[i]] = hash[t[i]] - 1;
				if (hash[t[i]]<0)
					return false;
			}
			else
				return false;
		}
		return true;

	}
};