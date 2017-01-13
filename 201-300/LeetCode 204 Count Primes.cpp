class Solution {
private:
	vector<int> PrimeTable;
private:
	bool isPrime(int n){
		if (n == 1)
			return false;
		for (int i=0;i<PrimeTable.size();i++){
			if (n%PrimeTable[i]==0)
				return false;
			if (PrimeTable[i] * PrimeTable[i] > n)
				break;
		}
		return true;
	}
public:
	int countPrimes(int n) {
		int count = 0;
		for (int i=1;i<n;i++)
			if (isPrime(i)){
				count++;
				PrimeTable.push_back(i);
			}
		return count;
	}
};