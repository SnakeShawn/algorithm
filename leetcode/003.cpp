/**
 * Question: 003
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 *		Given "abcabcbb", the answer is "abc", which the length is 3.
 *		Given "bbbbb", the answer is "b", with the length of 1.
 *		Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			if (s.length() == 0) return 0;
			int max = 0;
			int start = 0;
			unordered_map<char,int> hash;
			for (int i=0; i<s.length(); i++){
				if(hash.find(s[i]) != hash.end()){
					if (start < hash[s[i]]+1){
						start = hash[s[i]]+1;
					}
				}

				if (max < (i-start+1)){
					max = i-start+1;
				}
				hash[s[i]] = i;
			}
			return max;
		}
};

int main(){
	string str3 = "tmmzuxt";
	Solution s;
	cout<<s.lengthOfLongestSubstring(str3)<<endl;
	return 0;
}

