#include<vector>
#include<queue>
#include<array>
using namespace std;

int n, m;
vector<int> dist[100005];
priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq; //cost, r,c
const int dr[] = {0,0,1,-1};
const int dc[] = {1,-1,0,0};


class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i<n; i++)
        {
            dist[i].resize(m);
            for (int j = 0; j<m; ++j) dist[i][j] = INT_MAX;
        }
        while(pq.size()) pq.pop();
        
        dist[0][0] = 0;
        pq.push({0,0,0});
        int cost, r, c, nextCost;
        int nr, nc;

        while (!pq.empty())
        {
            cost = pq.top()[0];
            r = pq.top()[1];
            c = pq.top()[2];

            pq.pop();
            //skip data lama di pq
            if(cost > dist[r][c])
            {
                continue;
            }

            for (int i = 0; i<4; i++)
            {
                nr = r+dr[i];
                nc = c+dc[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m)
                {
                    continue;
                }
                nextCost = cost + grid[nr][nc];
                if (dist[nr][nc] > nextCost)
                {
                    dist[nr][nc] = nextCost;
                    pq.push({nextCost, nr, nc});
                }
            }
        }
        return dist[n-1][m-1];
    }
};