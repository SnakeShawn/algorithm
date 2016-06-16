/**
 * Question: 004
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
	private:
		int min(int a, int b){
			return a>b?b:a;
		}
		double findKth(vector<int>& nums1, int m, vector<int>::iterator iter1, vector<int>& nums2, int n, vector<int>::iterator iter2, int k){
			if (m>n){
				return findKth(nums2, n, iter2, nums1, m, iter1, k);
			}
			if (m==0){
				return *(iter2+k-1);
			}
			if (k==1){
				return min(*iter1, *iter2);
			}
			int pa = min(k/2, m), pb = k-pa;
			if (*(iter1+pa-1) < *(iter2+pb-1)){
				return findKth(nums1, m-pa, iter1+pa, nums2, n, iter2, k-pa);
			} else if (*(iter1+pa-1) > *(iter2+pb-1)){
				return findKth(nums1, m, iter1, nums2, n-pb, iter2+pb, k-pb);
			} else {
				return *(iter1+pa-1);
			}
		}
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int m = nums1.size(), n = nums2.size();
			if (m==0 && n==0) return 0.0f;
			int total = m+n;
			if (total%2){
				// (total/2) + 1
				return findKth(nums1, m, nums1.begin(), nums2, n, nums2.begin(), total/2+1);
			} else {
				// ((total/2) + (total/2+1))/2
				return findKth(nums1, m, nums1.begin(), nums2, n, nums2.begin(), total/2)/2 + findKth(nums1, m, nums1.begin(), nums2, n, nums2.begin(), total/2+1)/2;
			}
		}
};

int main(){
	//int ar2[]  = {};
	int ar1[] = {1, 12, 15, 26, 38};
	int ar2[] = {2, 13, 17, 30, 45, 50};
	vector<int> nums1(ar1, ar1+5);
	vector<int> nums2(ar2, ar2+6);
	Solution s;
	double median =  s.findMedianSortedArrays(nums1, nums2);
	cout<< median<<endl;
	return 0;
}
