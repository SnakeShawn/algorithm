/*
 * Question: 006
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *		P   A   H   N
 *		A P L S I I G
 *		Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *		string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
#include<iostream>
#include<string>

using namespace std;

class Solution {
	public:
		string convert(string s, int numRows) {
			int length = s.length();
			if (numRows>length || numRows <= 1)
				return s;
			string res;
			int step = 2*(numRows-1);
			for (int i; i<numRows; i++){
				int interval = step -2*i;

				for (int j=i; j<length; j+=step){
					res += s[j];
					if(interval>0 && interval<step && j+interval<length){
						res += s[j+interval];
					}
				}
			}
			return res;
		}
};

int main(){
	string str = "PAYPALISHIRING";
	Solution s;
	string res = s.convert(str, 3);
	cout<<res<<endl;
	return 0;
}
