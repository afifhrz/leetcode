#include<vector>
using namespace std;

class Solution {
public:
	bool checkIfExist(vector<int>& arr) {
		int sizeArr = arr.size();
		vector<int> anotherVec(sizeArr, 0);

		for (int i = 0; i < sizeArr; i++)
		{
			if (arr[i] % 2 == 0)
			{
				anotherVec[i] = arr[i] / 2;
			}
			else {
				anotherVec[i] = -1001;
			}
		}

		for (int i = 0; i < sizeArr; i++)
		{
			if (anotherVec[i] < -1000) continue;
			for (int j = 0; j < sizeArr; j++)
			{
				if (anotherVec[i] == arr[j] && i != j) return true;
			}
		}
		return false;
	}
};