#include<vector>
#include<queue>

using namespace std;

#define DIRCOUNT 4
class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		int direction[DIRCOUNT][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
		queue<pair<int, int>> q;
		int maxR = image.size();
		int maxC = image[0].size();
		vector<vector<int>> visited(maxR, vector<int>(maxC, 0));
		int sourceColor = image[sr][sc];
		
		image[sr][sc] = color;
		visited[sr][sc] = 1;
		q.push({ sr, sc });

		while (!q.empty())
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for (int i = 0; i < DIRCOUNT; i++)
			{
				int nextR = r + direction[i][0];
				int nextC = c + direction[i][1];

				if (nextR < 0 || nextC < 0 || nextR >= maxR || nextC >= maxC || image[nextR][nextC] != sourceColor || visited[nextR][nextC] == 1) continue;

				image[nextR][nextC] = color;
				visited[nextR][nextC] = 1;
				q.push({ nextR, nextC });
			}
		}
		return image;
	}
};