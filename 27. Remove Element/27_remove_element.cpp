#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int counter = 0;
        vector<int> result(length);
        for(int i = 0; i < length; i++)
        {
            if(nums[i] != val)
            {
                result[counter] = nums[i];
                counter++;
            };
        }
        nums = result;
        return counter;
    }
};
