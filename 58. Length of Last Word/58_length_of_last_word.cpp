#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int ans = 0;
		bool flag = false;
		for (int i = s.length() - 1; i > -1; i--)
		{
			if (s[i] == ' ' && !flag) continue;
			flag = true;
			if (s[i] == ' ') return ans;
			ans++;
		}
		return ans;
	}
};