/**
 * Question:001
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target. 
 * You may assume that each input would have exactly one solution.
 * 
 * Example:
 *		Given nums = [2, 7, 11, 15], target = 9,
 *
 *		Because nums[0] + nums[1] = 2 + 7 = 9,
 *		return [0, 1].
 *
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> hash;
			vector<int> result;
			for(int i=0; i<nums.size(); i++){
				if(hash.find(target - nums[i]) != hash.end()){
					result.push_back(hash[target-nums[i]]);
					result.push_back(i);
					return result;
				}
				hash[nums[i]] = i;
			}	
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
};


int main(){
	int array[4] = {2, 7, 11, 15};
	vector<int> nums(array, array+4);
	for (int i=0; i<nums.size(); i++){
		cout<<nums[i]<<endl;
	}

	int target = 13;
	Solution s;
	vector<int> result = s.twoSum(nums, target);
	cout<<"The result is:"<<endl;
	for (int i=0; i<result.size(); i++){
		cout<<result[i]<<endl;
	}
	
	return 0;
}
