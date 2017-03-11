#include <regex>
#include <algorithm>

class Solution {
private:
	string simple(string x){
		std::regex pattern("R{3,}|Y{3,}|B{3,}|G{3,}|W{3,}");
		while (std::regex_match(x.begin(), x.end(), pattern))
			std::regex_replace (x,pattern,"");
		return x;
	}
	int result = -1;
	void search(string x, map<char,int> hand_hash, int count){
		if (x.size()==0){
			if (result==-1)
				result = count;
			else
				result = min(result, count);
			return ;
		}
		current = 1;
		for (int i=1;i<x.size()+1;i++){
			
		}
	}

public:
	int findMinStep(string board, string hand) {

		map<char, int> hand_hash;
		hand_hash['R'] = 0;
		hand_hash['G'] = 0;
		hand_hash['B'] = 0;
		hand_hash['W'] = 0;
		hand_hash['B'] = 0;
		for (int i=0;i<hand.size(); i++)
			hand_hash[hand[i]] ++;

		simple(board);
		if (!board.size())
			return 0;
		search(board, hand_hash, 0);

		return result;

	}
};