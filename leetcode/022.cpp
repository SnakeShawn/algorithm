/**
 * Question: 022.Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *		[
 *			"((()))",
 *			"(()())",
 *		    "(())()",
 *	        "()(())",
 *	        "()()()"
 *		]
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution{
	private:
		void dfs(int left, int right, string s, vector<string>& result){
			if (left==0 && right==0){
				result.push_back(s);
			}
			if (left>0) 
				dfs(left-1, right, s+'(', result);
			if (right>left && right>0)
				dfs(left, right-1, s+')', result);
		}
	public:
		vector<string> generateParenthesis(int n) {
			vector<string> result;
			dfs(n, n, "", result);
			return result;
		}
};

int main(){
	
	Solution s;
	
	vector<string> result = s.generateParenthesis(3);
	for (int i=0; i<result.size(); i++){
		cout<<result[i]<<endl;
	}
	return 0;
}
