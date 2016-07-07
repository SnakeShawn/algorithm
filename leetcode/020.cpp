/**
 * Question: 020.Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution{

	public:
		bool isValid(string s){
			int len = s.length();
			if (len == 0) return true;
			vector<int> stack;
            stack.push_back(s[0]);
			for (int i=1; i<len; i++){
				if (s[i]=='{' || s[i]=='[' || s[i]=='('){
					stack.push_back(s[i]);
				} else if (s[i]=='}' || s[i]==']' || s[i]==')'){
					if(s[i]=='}' && stack.back()!='{'){
						return false;
					} else if(s[i]==']' && stack.back()!='['){
						return false;
					} else if(s[i]==')' && stack.back()!='('){
						return false;
					} else {
						stack.pop_back();
					}
				} 
			}
			if (stack.empty()) return true;
			else return false;
			
		}
};

int main(){
	string str = "[([]00](){}";
	Solution s;
	cout<<s.isValid(str)<<endl;
	return 0;
}
