#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int firstPointer = 0;
        int secondPointer = 0;
        int totalSize = nums1.size() + nums2.size();
        int maxLoop;
        bool isOdd = false;

        if (totalSize % 2 == 0)
        {
            maxLoop = totalSize / 2;
        }
        else 
        {
            maxLoop = totalSize / 2 + 1;
            isOdd = true;
        }

        while (firstPointer + secondPointer + 2 < maxLoop)
        {
            if (nums1[firstPointer] < nums2[secondPointer])
            {
                firstPointer++;
            } 
            else 
            {
                secondPointer++;
            }
        }

        //calculate median
        if (isOdd)
        {
            if 
            return 
        }
    }
};