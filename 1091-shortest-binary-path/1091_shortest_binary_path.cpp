#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid.back().back() == 1) return -1;
        vector<pair <int, int>> direction = {
            {0, -1},{1, -1},{1, 0},{1, 1},{0, 1},{-1, 1},{-1, 0},{-1, -1}
            };
        queue<pair <int, int>> q;
        q.push({0, 0});
        int distance[100][100];
        for (int i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                distance[i][j] = 0;
            }
        }
        
        distance[0][0] = 1;
        while (!q.empty()) 
        {
            pair <int, int> current = q.front();
            q.pop();
            for (size_t i = 0; i < direction.size(); i++)
            {
                int x = current.first + direction[i].first;
                int y = current.second + direction[i].second;
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0)
                {
                    distance[x][y] = distance[current.first][current.second] + 1;
                    grid[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        if (distance[grid.size()-1][grid[0].size()-1] == 0)
        {
            return -1;
        }
        return distance[grid.size()-1][grid[0].size()-1];
    }
};
