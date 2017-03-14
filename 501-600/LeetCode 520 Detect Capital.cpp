class Solution {
private:
	bool isCapital(char x){
		if (x>='A' && x<='Z')
			return true;
		return false;
	}
public:
	bool detectCapitalUse(string word) {

		bool AllCapital;
		AllCapital = true;
		for (int i=0;i<word.size();i++)
			if (isCapital(word[i]) == true)
				continue;
			else
				AllCapital = false;
				
		if (AllCapital)
			return true;

		bool AllNotCapital;
		AllNotCapital = true;
		for (int i=0;i<word.size();i++)
			if (isCapital(word[i]) == true)
				AllNotCapital = false;
			else
				continue;
		
		if (AllNotCapital)
			return true;

		bool NotCapitalExceptFirst;
		NotCapitalExceptFirst = true;
		for (int i=1;i<word.size();i++)
			if (isCapital(word[i]))
				NotCapitalExceptFirst = false;
			else
				continue;
		
		if (NotCapitalExceptFirst)
			return true;
			
		return false;
	}
};