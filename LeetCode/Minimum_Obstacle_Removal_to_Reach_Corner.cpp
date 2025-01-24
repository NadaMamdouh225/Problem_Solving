#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int bfs(std::vector<std::vector<int>>&grid)
    {
        int n =grid.size();
        int m = grid[0].size();
        std::queue<std::pair<int,int>>q;
        q.push({0,0});
        std::vector<std::vector<int>> dist(n,std::vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        while(!q.empty())
        {
            auto[x,y] = q.front();
            q.pop();
            for(int i =0;i<4;i++)
            {
                int ddx = dx[i] + x;
                int ddy = dy[i] + y;
                // boundry constrain
                if(ddx >= 0 && ddy >= 0 && ddx<n && ddy<m)
                {
                    int newDist = dist[x][y] + grid[ddx][ddy];
                    if(dist[ddx][ddy] > newDist)
                    {
                        dist[ddx][ddy] = newDist;
                        // push children
                        q.push({ddx,ddy});
                    }
                }
            }
            
        }
        return dist[n-1][m-1];
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
