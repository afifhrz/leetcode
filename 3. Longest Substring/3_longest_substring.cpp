#define NOMINMAX
#define max(a,b)            (((a) > (b)) ? (a) : (b))

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		unordered_set<char> charSet;
		int left = 0;
		int n = s.length();
		int maxLength = 0;

		for (int right = 0; right < n; right++)
		{
			if (charSet.count(s[right]) == 0)
			{
				charSet.insert(s[right]);
				maxLength = max(maxLength, right - left + 1);
			}
			else
			{
				while (charSet.count(s[right]))
				{
					charSet.erase(s[left]);
					left++;
				}
				charSet.insert(s[right]);
			}
		}
		return maxLength;
    }
};