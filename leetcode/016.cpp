/**
 * Question: 016. 3Sum Closest
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *		For example, given array S = {-1 2 1 -4}, and target = 1.
 *		The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution{

	public:
		int threeSumClosest(vector<int>& nums, int target){
			int result = nums[0]+nums[1]+nums[2];
			int len = nums.size();
			sort(nums.begin(), nums.end());

			for (int i=0; i<len-2; i++) {
				int j = i+1;
				int k = len-1;
				while (j<k) {
					int sum = nums[i]+nums[j]+nums[k];
					if (abs(sum-target)<abs(result-target))
						result = sum;
					if (sum<target) {
						j++;
					} else if (sum>target) {
						k--;
					} else {
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
	int array[4] = {-1, 2, 1, 4};
	vector<int> nums(array, array+4);
	Solution s;
	cout<<s.threeSumClosest(nums, 1);
	return 0;
}
