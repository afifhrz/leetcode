#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		bool isEven = false;
		int totalSize = nums1.size() + nums2.size();
		if (totalSize % 2 == 0)
		{
			isEven = true;
		}
		int midPoint = totalSize / 2 + 1;

		int firstPointer = 0;
		int secondPointer = 0;
		int index = 0;
		double result[2010];

		while (true)
		{
			if (firstPointer >= nums1.size())
			{
				result[index] = nums2[secondPointer];
				secondPointer++;
				index++;
				if (index == midPoint)
				{
					break;
				}
				continue;
			}

			if (secondPointer >= nums2.size())
			{
				result[index] = nums1[firstPointer];
				firstPointer++;
				index++;
				if (index == midPoint)
				{
					break;
				}
				continue;
			}

			if (nums1[firstPointer] < nums2[secondPointer])
			{
				result[index] = nums1[firstPointer];
				firstPointer++;
			}
			else
			{
				result[index] = nums2[secondPointer];
				secondPointer++;
			}
			index++;

			if (index == midPoint)
			{
				break;
			}
		}
		// for(int i = 0; i < 4; i++)
		// {
		//     printf("%d\n", result[i]);
		// }

		// calculate median
		if (isEven)
		{
			return (result[midPoint - 1] + result[midPoint - 2]) / 2;
		}
		return result[midPoint - 1];
	}
};