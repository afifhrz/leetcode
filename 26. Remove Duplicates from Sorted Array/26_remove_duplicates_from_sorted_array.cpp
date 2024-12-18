#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int current = nums[0];
		int iter = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			if (current == nums[i])
			{
				continue;
			}
			else
			{
				current = nums[i];
				iter++;
				nums[iter] = current;
			}
		}
		return iter + 1;
	}
};