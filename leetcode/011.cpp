/**
 * Question: 011
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container.
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution{

	public:
		int maxArea(vector<int>& height){
			int volume = 0;	
			int i = 0;
			int j = height.size()-1;
			while (i<j){
				int h = height[i]>height[j]?height[j]:height[i];
				int w = j-i;
				if (w*h > volume)
					volume = w*h;
				if (height[i]>height[j])
					j--;
				else
					i++;
			}
			return volume;
		}
};

int main(){
	int array[6] = {1, 2, 13, 14, 5, 6};
	vector<int> height(array, array+6);
	Solution s;
	cout<<s.maxArea(height)<<endl;
	return 0;
}
