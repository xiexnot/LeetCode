class Solution {
private:
	string base_string(int i){
		if (i==0)
			return "";
		if (i==1)
			return "Thousand ";
		if (i==2)
			return "Million ";
		if (i==3)
			return "Billion ";
		return "";
	}
	string number_string(int i){
		if (i>=100)
			return number_string(i/100) + "Hundred " + number_string(i%100);

		if (i==0)
			return "";

		if (i<=10 && i>0){
			switch (i){
				case 1: return "One ";
				case 2: return "Two ";
				case 3: return "Three ";
				case 4: return "Four ";
				case 5: return "Five ";
				case 6: return "Six ";
				case 7: return "Seven ";
				case 8: return "Eight ";
				case 9: return "Nine ";
				case 10: return "Ten ";
			}
		}

		if (i<=19 && i>10){
			switch (i){
				case 11: return "Eleven ";
				case 12: return "Twelve ";
				case 13: return "Thirteen ";
				case 14: return "Fourteen ";
				case 15: return "Fifteen ";
				case 16: return "Sixteen ";
				case 17: return "Seventeen ";
				case 18: return "Eighteen ";
				case 19: return "Nineteen ";
			}	
		}

		if (i>=20 && i<100){
			switch (i/10){
				case 2: return "Twenty " + number_string(i%10);
				case 3: return "Thirty " + number_string(i%10);
				case 4: return "Forty " + number_string(i%10);
				case 5: return "Fifty " + number_string(i%10);
				case 6: return "Sixty " + number_string(i%10);
				case 7: return "Seventy " + number_string(i%10);
				case 8: return "Eighty " + number_string(i%10);
				case 9: return "Ninety " + number_string(i%10);
			}
		}
	}
public:
	string numberToWords(int num) {
		// check whether the number is zero
		if (num==0){
			return "Zero";
		}

		// split num into components with three digits
		vector<int> split_num;
		while (num!=0){
			split_num.push_back(num%1000);
			num = num/1000;
		}
		if (split_num.size()==0)
			split_num.push_back(0);

		string resultString = "";
		for (int i=split_num.size()-1; i>=0;i--){
			if (split_num[i]==0)
				continue;
			resultString = resultString + number_string(split_num[i]) +base_string(i);
		}

		while (resultString.size()>0 && resultString[resultString.size()-1]==' ')
			resultString.erase(resultString.size()-1,1);
		return resultString;

	}
};