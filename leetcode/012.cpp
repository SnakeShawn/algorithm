/**
 * Question: 012
 * Give an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */
#include<iostream>

using namespace std;

class Solution{

	public:
		string intToRoman(int num){
			if (num<1 || num>3999) return "";
			string m[][10] = {
				{"", "M", "MM", "MMM"},
				{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
				{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
				{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
			};
			string str = "";
			for (int i=0, base=1000; i<4;i++){
				str += m[i][num/base];
				num %= base;
				base /=10;
			}

			return str;
		}
};

int main(){
	int num = 3999;
	Solution s;
	cout<<s.intToRoman(num);
	return 0;
}
