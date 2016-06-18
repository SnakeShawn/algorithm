/**
 * Question: 005
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of 
 * S is 1000, and there exists one unique longest palindromic substring.
 */
#include<iostream>
#include<string>
using namespace std;

class Solution{
	private:
		string insertSharp(string s){
			string res = "$";
			for (int i=0; i<s.length(); i++){
				res += '#';
				res += s[i];
			}
			res += '#';
			return res;
		}
	public:
		string longestPalindrome(string s){
			if (s.length()==1 || s.length()==0)return s;
			string alterstr = insertSharp(s);
			int len = alterstr.length();
			int maxlen = 0;
			int index = 0;

			string palindrome;
			int * p = new int[len];
			p[0] = 0;

			int id = 0;
			for (int i=0; i<alterstr.length()-1; i++){
				if (p[id]+id>i)			// if i in a palindrome string before i.
					p[i] = min(p[2*id-i], p[id]+id-i);
				else
					p[i] = 1;
				while (i-p[i]>=0 && i+p[i]<len && alterstr[i-p[i]] == alterstr[i+p[i]])
					p[i] ++;
				if (id+p[id] < i+p[i])		// farthest from start of string.
					id = i;
				if (maxlen<p[i]){
					maxlen = p[i];
					index = i;
				}
			}
			
			delete[] p;
			palindrome = s.substr((index-maxlen+1)/2, maxlen-1);
			return palindrome;
		}
};

int main(){
	
	string str = "qwertrewq";
	Solution s;
	cout<<s.longestPalindrome(str);
	return 0;
}
