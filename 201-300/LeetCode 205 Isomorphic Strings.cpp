class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char,char> Hash1, Hash2;
		// Hash1: s->t
		// Hash2: t->s
		map<char,char>::iterator it1, it2;
		char c1,c2;
		for (int i=0;i<s.size();i++){
			c1 = s[i];
			c2 = t[i];
			it1 = Hash1.find(c1);
			it2 = Hash2.find(c2);
			// 两方都找不到
			if (it1==Hash1.end() && it2==Hash2.end()){
				Hash1[c1] = c2;
				Hash2[c2] = c1;
				continue;
			}
			// 两方都找到
			if (it1!=Hash1.end() && it2!=Hash2.end()){
				if (Hash1[c1] != c2 || Hash2[c2] != c1)
					return false;
				continue;
			}
			// 两方其中有一方找不到
			return false;
		}
		return true;
	}
};