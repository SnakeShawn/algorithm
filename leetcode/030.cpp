/**
 * Question: 030.Substring with Concatenation of All Words
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 *
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 */
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution{

	public:
		vector<int> findSubstring(string s, vector<string>& words) {
			vector<int> result;
			if (s.length()==0||words.size()==0) return result;
			int wordlen = words[0].length();
			if (s.length() < wordlen) return result;

			unordered_map<string, queue<int> > wordhash; // word and appearing positions.
			unordered_map<string, queue<int> >::iterator it;
			queue<int> Q;
			Q.push(-1);
			for (int i=0; i<words.size(); i++){
				it = wordhash.find(words[i]);
				if (it == wordhash.end()){
					wordhash[words[i]] = Q;
				} else {
					it->second.push(-1);
				}
			}
			unordered_map<string, queue<int> > temp = wordhash;
			for (int i=0; i<wordlen; i++){
				int currWordCnt = 0;
				wordhash = temp;
				for (int index=i; index<=s.size()-wordlen; index+=wordlen){
					it = wordhash.find(s.substr(index, wordlen));
					if (it == wordhash.end()){
						currWordCnt = 0;
					} else {
						int lastPos = it->second.front();
						if (lastPos == -1){
							currWordCnt ++;
						} else if (currWordCnt*wordlen < index-lastPos) {
							currWordCnt++;
						} else {
							currWordCnt = (index-lastPos)/wordlen;
						}
						it->second.pop();
						it->second.push(index);
						if (currWordCnt == words.size()) {
							result.push_back(index-wordlen*(words.size()-1));
						}
					}
				}
			}

			return result;
		}
};

int main(){
	const string arr[] = {"foo","bar"};
	vector<string> words(arr, arr+2);
	Solution s;
	vector<int> result = s.findSubstring("foobarbarfoo", words);
	for (int i=0; i<result.size(); i++){
		cout<<result[i]<<endl;
	}
	return 0;
}
