/**
 * Question: 028. Implement strStr()
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 */
#include<iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; ; i++){
            for(int j = 0; ; j++){
                if(j == needle.length())
                    return i;
                if(i + j == haystack.length())
                    return -1;
                if(haystack[i + j] != needle[j])
                    break;
            }
        }
    }
};

int main(){
	
	Solution s;
	cout<<s.strStr()<<endl;
	return 0;
}
