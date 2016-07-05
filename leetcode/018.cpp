/**
 * Question: 018.4Sum
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
 * Find all unique quadruplets in the array which gives the sum of target.
 *		For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 *		A solution set is:
 *		[
 *			[-1,  0, 0, 1],
 *			[-2, -1, 1, 2],
 *		    [-2,  0, 0, 2]
 *		]
 */
#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution{

	public:
		vector< vector<int> > fourSum(vector<int>& nums, int target) {
			vector< vector<int> > result;
			int len = nums.size();
			if (len<4) return result;
			sort(nums.begin(), nums.end());
			
			set< vector<int> > tmpres;

			for (int i=0; i<len; i++){
				for (int j=i+1; j<len; j++){
					int begin = j+1;
					int end = len-1;

					while(begin<end){
						int sum = nums[i]+nums[j]+nums[begin]+nums[end];
						if(sum == target){
							vector<int> tmp;
							tmp.push_back(nums[i]);
							tmp.push_back(nums[j]);
							tmp.push_back(nums[begin]);
							tmp.push_back(nums[end]);
							tmpres.insert(tmp);
							begin++;
							end--;
						} else if (sum<target) begin++;
						else end--;
					}
				}
			}
			set< vector<int> >::iterator it = tmpres.begin();
			for (; it!=tmpres.end(); it++){
				result.push_back(*it);
			}
			return result;
		}
};

int main(){
	int array[6] = {1, 0, -1, 0, -2, 2};
	vector<int> nums(array, array+6);
	Solution s;
	vector< vector<int> > result = s.fourSum(nums, 1);
	for (int i=0; i<result.size(); i++) {
		for (int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
	return 0;
}
