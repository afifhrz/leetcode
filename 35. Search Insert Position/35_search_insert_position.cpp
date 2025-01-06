#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int end = nums.size();
		int start = 0;
		if (target > nums[nums.size() - 1]) return nums.size();

		while (start <= end)
		{
			int mid = (end + start) / 2;
			if (nums[mid] == target) return mid;

			if (nums[mid] < target)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		return start;
	}
};