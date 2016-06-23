/**
 * Question: 013. Roman to Integer
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be with in the range from 1 to 3999.
 */
#include<iostream>

using namespace std;

class Solution{
	private:
		int val[255];
		void init(){
			val['I'] = 1; val['V'] = 5; val['X'] = 10; val['L'] = 50;  
			val['C'] = 100; val['D'] = 500; val['M'] = 1000;
		}
	public:
		int romanToInt(string s){
			init();
			int ret = 0;
			for (int i=0; i<s.size(); i++){
				if (i>0 && val[s[i]] > val[s[i-1]]){
					ret += val[s[i]] - 2*val[s[i-1]];
				} else {
					ret += val[s[i]];
				}
			}
			return ret;
		}
};

int main(){
	string str = "IV";
	Solution s;
	cout<<s.romanToInt(str);
	return 0;
}
