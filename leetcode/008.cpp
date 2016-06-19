/**
 * Question: 008
 * Implement atoi to convert a string to an integer.
 */
#include<iostream>

using namespace std;

class Solution{

	public:
		int myAtoi(string str) {
			int result = 0;
			bool overflow = false;
			int len = str.length();
			int sign = 1;	//1==+,-1==-, defalut is 1
			int i  = 0;
			while (i<len && (str[i]==' ' || str[i]=='\t' || str[i]=='\n')){	
				// remove the ' ','\t','\n' at the begining of string.
				i++;
			}
			if(i == len){
				return 0;
			}
			if(str[i] == '-'){
				sign = -1;
				i++;
			} else if (str[i] == '+'){
				i++;
			}

			while (i<len){
				if (!isdigit(str[i]))
					break;
				int num = str[i]-'0';
				if ((sign==1 && result>(INT_MAX-num)/10)||
						(sign==-1 && -1*result<(INT_MIN+num)/10)){
					overflow = true;
					break;
				}

				result = result*10+(str[i]-'0');
				i++;
			}
			
			if (overflow)
				result = (sign == 1)?INT_MAX:INT_MIN;
			else
				result *= sign;
			return result;
		}
};

int main(){
	string str = "-oooo";
	Solution s;
	cout<<s.myAtoi(str)<<endl;
	return 0;
}
