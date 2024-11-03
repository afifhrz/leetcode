#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> FirstIslandArr;
    vector<pair<int,int>> DirectionArr;
    vector<vector<int>> Distance;
    
    void scanFirstIsland(vector<vector<int>> grid)
    {
        queue<pair<int,int>> q;
        vector<vector<int>> visited (grid.size(), vector<int> (grid[0].size(), 0));

        bool isFound = false;
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i,j});
                    FirstIslandArr[i][j] = 1;
                    visited[i][j] = 1;
                    isFound = true;
                    break;
                }
            }
            if(isFound)
            {
                break;
            }
        }
        
        while (!q.empty())
        {
            pair<int,int> current = q.front();
            q.pop();
            for (size_t i = 0; i < DirectionArr.size(); i++)
            {
                int x = current.first + DirectionArr[i].first;
                int y = current.second + DirectionArr[i].second;

                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1 && visited[x][y] == 0)
                {
                    FirstIslandArr[x][y] = 1;
                    visited[x][y] = 1;
                    q.push({x,y});
                }
            }
        }
        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        FirstIslandArr = vector<vector<int>> (grid.size(), vector<int> (grid[0].size(), 0));
        Distance = vector<vector<int>> (grid.size(), vector<int> (grid[0].size(), 9999999));
        vector<vector<int>> visited (grid.size(), vector<int> (grid[0].size(), 0));
        int result = 99999;

        DirectionArr = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        scanFirstIsland(grid);

        queue<pair<int,int>> q;

        bool isFound = false;
        for (size_t i = 0; i < FirstIslandArr.size(); i++)
        {
            for (size_t j = 0; j < FirstIslandArr[0].size(); j++)
            {
                if (FirstIslandArr[i][j] == 1)
                {
                    q.push({i,j});
                    Distance[i][j] = 0;
                    visited[i][j] = 1;
                }
            }
        }
        
        while (!q.empty())
        {
            pair<int,int> current = q.front();
            q.pop();
            for (size_t i = 0; i < DirectionArr.size(); i++)
            {
                int x = current.first + DirectionArr[i].first;
                int y = current.second + DirectionArr[i].second;

                // meet the first island
                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1 && FirstIslandArr[x][y] == 1 && visited[x][y] == 0)
                {
                    Distance[x][y] = min(Distance[current.first][current.second], Distance[x][y]);
                    q.push({x,y});
                    visited[x][y] = 1;
                    continue;
                }
                // found water
                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 0 && FirstIslandArr[x][y] == 0 && visited[x][y] == 0)
                {
                    Distance[x][y] = min(Distance[current.first][current.second] + 1, Distance[x][y]);
                    q.push({x,y});
                    visited[x][y] = 1;
                    continue;
                }
                // found second island
                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1 && FirstIslandArr[x][y] == 0 && visited[x][y] == 0)
                {
                    Distance[x][y] = min(Distance[current.first][current.second] + 1, Distance[x][y]);
                    visited[x][y] = 1;
                    result = min(result, Distance[x][y]-1);
                    continue;
                }
            }
        }
        return result;
    }
};