/**
 * Question: 009
 * Determine whether an integer is a palindrome. Do this without extra space.
 */
#include<iostream>

using namespace std;

class Solution{

	public:
		bool isPalindrome(int x) {
			if (x<0) return false;
			int base = 1;
			while (x/base >= 10){
				base *= 10;
			}
			int left = 0;
			int right = 0;
			while(x){
				left = x/base;
				right = x%10;
				if (left!=right)
					return false;
				x = (x-left*base-right)/10;
				base /=100;
			}
			return true;
		}
};

int main(){
	int num = 12321;
	Solution s;
	cout<<s.isPalindrome(num);
	return 0;
}
