#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
		vector<int> mentionsCount(numberOfUsers, 0);
		vector<int> offlineTime(numberOfUsers, -60);
		int all_count = 0;
		
		sort(events.begin(), events.end(),
			[](const auto& a, const auto& b) {
				int ai = std::stoi(a[1]);
				int bi = std::stoi(b[1]);

				// 1. Sort by second item numerically
				if (ai != bi)
					return ai < bi;

				// 2. If tie, OFFLINE first
				bool aOffline = (a[0] == "OFFLINE");
				bool bOffline = (b[0] == "OFFLINE");

				return aOffline > bOffline; // true before false
			}
		);

		for (const auto& event : events) {
			if (event[0][0] == 'M') {
				int timestamp = stoi(event[1]);
				string command = event[2];

				if (command[0] == 'A') {
					all_count++;
				}
				else if (command[0] == 'H') {
					for (int i = 0; i < numberOfUsers; ++i) {
						if (timestamp - offlineTime[i] >= 60) {
							mentionsCount[i]++;
						}
					}
				}
				else
				{
					int i = 0;
					string& ids = command;
					const int m = ids.size();
					while (i < m) {
						int num = 0;
						i += 2;
						while (i < m && ids[i] != ' ') {
							num = (ids[i++] - '0') + num * 10;
						}
						++mentionsCount[num];
						++i;
					}
				}
			}
			else if (event[0] == "OFFLINE") {
				int timestamp = stoi(event[1]);
				int userId = stoi(event[2]);
				offlineTime[userId] = timestamp;
			}
		}
		for (int i = 0; i < numberOfUsers; i++)
		{
			mentionsCount[i] += all_count;
		}
		return mentionsCount;
    }
};