/**
 * Question: 015. 3Sum
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 *
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution{

	public:
		vector< vector<int> > threeSum(vector<int>& nums){
			vector< vector<int> > result;
			int len = nums.size();
			if (len<3)
				return result;
			sort(nums.begin(), nums.end());
			for (int i=0; i<len-2; i++){
				int j = i+1;
				int k = len-1;
				int tar = 0-nums[i];
				while (j<k) {
					if (nums[j]+nums[k] < tar){
						j++;
					} else if (nums[j]+nums[k] > tar) {
						k--;
					} else {
						vector<int> tmp;
						tmp.push_back(nums[i]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[k]);
						result.push_back(tmp);
						j++;
						k--;
						while (j<k && nums[j]==nums[j-1])
							j++;
						while (j<k && nums[k]==nums[k+1])
							k--;
					}
				}
				while (i<len-2 && nums[i]==nums[i+1])
					i++;
			}
			return result;
		}
};

int main(){
	int array[6] = {-1, 0, 1, 2, -1, -4};
	vector<int> nums(array, array+6);
	Solution s;
	vector< vector<int> > ret = s.threeSum(nums);
	for (int i=0; i<ret.size(); i++) {
		for (int j=0; j<ret[i].size(); j++){
			cout<<ret[i][j]<<",";
		}
		cout<<endl;
	}
}
