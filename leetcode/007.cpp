/**
 * Question: 007
 * Reverse digits of an integer.
 *		Example1: x = 123, return 321
 *		Example2: x = -123, return -321
 */
#include<iostream>

using namespace std;

class Solution{
	public:
		int reverse(int x){
			long long result = 0;
			bool negNum = false;
			if (x<0) negNum = true;
			long long tmp = abs((long long)x);
			while(tmp>0){
				result = result*10 + tmp%10;
				if (result > INT_MAX)return 0;
				tmp = tmp/10;
			}
			
			if(negNum) return (int)result*(-1);
			return (int)result;
		}
};

int main(){
	int integer = -123;
	Solution s;
	cout<<integer<<endl;
	cout<<s.reverse(integer)<<endl;
	return 0;
}
