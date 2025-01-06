#define NOMINMAX
#define max(a,b)            (((a) > (b)) ? (a) : (b))

#include<vector>
using namespace std;

class Solution {
public:
	int countBalls(int lowLimit, int highLimit) {
		vector<int> box(46);
		int result = 0;

		for (int i = lowLimit; i < highLimit + 1; i++)
		{
			int boxId = 0;
			int ballId = i;
			while (ballId != 0)
			{
				boxId += ballId % 10;
				ballId /= 10;
			}
			box[boxId]++;
			result = max(box[boxId], result);
		}
		return result;
	}
};