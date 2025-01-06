#include<string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.length() == needle.length() && haystack == needle) return 0;
		if (haystack.length() < needle.length()) return -1;

		for (int i = 0; i < haystack.length() - needle.length() + 1; i++)
		{
			bool ans = true;
			for (int j = 0; j < needle.length(); j++)
			{
				if (haystack[i + j] != needle[j])
				{
					ans = false;
				}
			}
			if (ans)
			{
				return i;
			}
		}
		return -1;
	}
};