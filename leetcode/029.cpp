/**
 * Question: 029. Divide Two Integers
 * Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
 */
#include<iostream>

using namespace std;

class Solution{

	public:
		int divide(int dividend, int divisor) {
			if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
			long long a = dividend>=0 ? dividend : -(long long)dividend;
			long long b = divisor>=0 ? divisor : -(long long)divisor;
			bool sign = (dividend>0&&divisor<0) || (dividend<0&&divisor>0); // true:-, false:+
			long long c = 0;
			long long result = 0;
			while (a >= b) {
				c = b;
				for (int i=0; c<=a; i++, c<<=1) {
					a -= c;
					result += (1<<i);
				}
			}
			cout<<(long long)INT_MIN<<endl;
			cout<<-result<<endl;
			if (sign) return max((long long)INT_MIN, -result);  
			else return min((long long)INT_MAX, result);

		}
};

int main(){
	
	Solution s;
	cout<<s.divide(1004958205, -2137325331)<<endl;
	return 0;
}
