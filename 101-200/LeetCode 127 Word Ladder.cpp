#include <iostream>
#include <cstring>
#include <string> 
#include <queue>
#include <vector> 
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    	if (beginWord==endWord){
    		return 0;
		}
    	queue<string> BFSQueueString;
    	queue<int> BFSQueueLength;
    	unordered_set<string> BFSHash;
    	string currentString, nextString;
    	int currentLength;
    	
    	BFSQueueString.push(beginWord);
    	BFSQueueLength.push(1);
    	BFSHash.insert(beginWord);
    	
    	while (BFSQueueLength.empty() == false){
    		currentString = BFSQueueString.front();
    		currentLength = BFSQueueLength.front();
    		BFSQueueString.pop();
    		BFSQueueLength.pop();
    		
			for (int i=0;i<currentString.size();i++){
				nextString = currentString; 
				for (char ch='a';ch<='z';ch++) {
					if (ch == currentString[i])
						continue;
					// find in wordList and not find in BFSHash
					nextString[i] = ch;
					if (wordList.find(nextString)!=wordList.end() && BFSHash.find(nextString)==BFSHash.end()){
						BFSHash.insert(nextString);
						BFSQueueString.push(nextString);
						BFSQueueLength.push(currentLength+1);
						if (nextString == endWord)
							return currentLength + 1;
					} 
					
				}
			} 
		}
        return 0;
    }
};

int main(){
	return 0;
}
