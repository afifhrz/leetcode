#include <string>
using namespace std;

class Solution {
public:
	bool isPositive = true;
	int myAtoi(string s) {
		bool isFirstCharFound = false;
		bool isPositiveFound = false;
		string answer = "";
		for (int i = 0; i < s.size(); i++)
		{
			char chr = s[i];
			if (isWhiteSpace(chr) && !isFirstCharFound && !isPositiveFound)
			{
				continue;
			}
			if (chr == '-' && !isFirstCharFound && isPositive && !isPositiveFound)
			{
				isPositive = false;
				isPositiveFound = true;
				continue;
			}
			if (chr == '+' && !isFirstCharFound && !isPositiveFound)
			{
				isPositiveFound = true;
				continue;
			}

			if (!isdigit(chr) && !isFirstCharFound)
			{
				return 0;
			}
			if (isdigit(chr) && !isFirstCharFound)
			{
				isFirstCharFound = true;
				answer += chr;
				continue;
			}
			if (isdigit(chr))
			{
				answer += chr;
				continue;
			}

			if (chr == '0' && !isFirstCharFound)
			{
				continue;
			}

			if (!isdigit(chr))
			{
				break;
			}
		}
		int result = convertStringToInt(answer);
		return result;
	}
	int convertStringToInt(string s)
	{
		long long i = 0;
		long long range = pow(2, 31);

		// Traversing string
		for (char c : s) {
			// Checking if the element is number
			if (c >= '0' && c <= '9') {
				i = i * 10 + (c - '0');
				if (-range > i)
				{
					i = -range;
					break;
				}
				if (range - 1 < i)
				{
					if (!isPositive)
					{
						i = range;
						break;
					}
					i = range - 1;
					break;
				}
			}
			// Otherwise print bad output
			else {
				return 1;
			}
		}
		if (!isPositive)
		{
			i = i * -1;
		}
		return i;
	}

	bool isWhiteSpace(char s)
	{
		return s == ' ';
	}
};