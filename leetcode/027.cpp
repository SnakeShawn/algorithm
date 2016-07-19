/**
 * Question: 027.Remove Element
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 *
 * Your function should return length = 2, with the first two elements of nums being 2.
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution{

	public:
		int removeElement(vector<int>& nums, int val) {
			int length = nums.size();
			int index = 0;
			for (int i=0; i<length; i++){
				if (nums[i] != val){
					nums[index] = nums[i];
					index ++;
				}
			}
			return index;
		}
};

int main(){
	int a[4] = {3,2,2,3};
	vector<int> nums(a, a+4);
	Solution s;
	cout<<s.removeElement(nums, 3);

	return 0;
}
