#include<queue>
using namespace std;
class Solution {
public:
	int minimumTime(vector<vector<int>>& grid) {
		//base case return - 1
		if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

		int directionX[] = { 0, 1, 0, -1 };
		int directionY[] = { 1, 0, -1, 0 };
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<bool>> visited(row, vector<bool>(col, false));

		// edit grid with parity
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] % 2 != (i + j) % 2) grid[i][j] += 1;
			}
		}

		pq.push(pair<int, pair<int, int>> {0, { 0, 0 }});
		while (!pq.empty())
		{
			pair<int, pair<int, int>> current = pq.top();
			pq.pop();

			int time = current.first;
			int x = current.second.first;
			int y = current.second.second;

			if (x == row - 1 && y == col - 1) return time;
			if (visited[x][y]) continue;
			visited[x][y] = true;

			for (int i = 0; i < 4; i++)
			{
				int dx = directionX[i];
				int dy = directionY[i];
				int nextX = x + dx;
				int nextY = y + dy;

				if (nextX < 0 || nextX >= row || nextY < 0 || nextY >= col || visited[nextX][nextY]) continue;

				int nextTime;
				if (time + 1 > grid[nextX][nextY])
				{
					nextTime = time + 1;
				}
				else
				{
					nextTime = grid[nextX][nextY];
				}
				pq.push(pair<int, pair<int, int>> {nextTime, { nextX, nextY }});
			}
		}
		return -1;
	}
};