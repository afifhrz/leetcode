#include<string>
#include<vector>
using namespace std;

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string shiftingLetters(string s, vector<vector<int>>& shifts) {
		vector<int> prefixDiff(s.length() + 1, 0);
		for (int i = 0; i < shifts.size(); i++)
		{
			int start = shifts[i][0];
			int end = shifts[i][1];
			int direction = shifts[i][2];

			prefixDiff[start] += (direction == 1 ? 1 : -1);
			prefixDiff[end + 1] -= (direction == 1 ? 1 : -1);
		}

		int currentShift = 0;
		for (int i = 0; i < s.length(); ++i) {
			currentShift += prefixDiff[i];
			prefixDiff[i] = currentShift;
		}

		for (int i = 0; i < s.length(); i++)
		{
			s[i] = 'a' + ((s[i] - 'a' + prefixDiff[i]) % 26 + 26) % 26;
		}

		return s;
	}
};