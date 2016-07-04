/**
 * Question: 017.Letter Combinations of a Phone Number
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *	Input:Digit string "23"
 *	Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution{
	private:
		const string alpha[10] = {
			"",
			"1", "abc", "def",
			"ghi", "jkl", "mno",
			"pqrs", "tuv", "wxyz"
		};
		void dfs(vector<string> &res, string &ab, string &digits, int cur){
			if (cur >= digits.length()){
				res.push_back(ab);
				return;
			}
			for (int i=0; i<alpha[digits[cur]-'0'].size(); i++){
				ab.push_back(alpha[digits[cur]-'0'][i]);
				dfs(res, ab, digits, cur+1);
				ab.pop_back();
			}
		}
	public:
		vector<string> letterCombinations(string digits) {
			vector<string> res;
			if (digits.length()==0) return res;
			string alphas;
			dfs(res, alphas, digits, 0);
			return res;
		}
};

int main(){
	string str ="";
	Solution s;
	vector<string> res = s.letterCombinations(str);
	for (auto r : res){
		cout<<r<<endl;
	}
	return 0;
}
