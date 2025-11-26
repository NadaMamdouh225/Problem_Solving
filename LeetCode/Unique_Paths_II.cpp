class Solution {
public:
    int m, n; 
    vector<vector<int>> memo;
    int paths(int r, int c, vector<vector<int>>& obstacleGrid)
    {
        
        // out of boundry
        if (r>m-1 || c>n-1 || r<0 || c<0 || (obstacleGrid[r][c]==1))   return 0;

        // reached the goal
        if(r == m-1 && c == n-1)
            return 1;

        if(memo[r][c]!= -1) return memo[r][c];

        int down = paths(r+1, c, obstacleGrid);
        int right = paths(r, c+1, obstacleGrid);

        return memo[r][c] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memo.resize(m, vector<int>(n,-1));

        return paths(0, 0, obstacleGrid);
    }
};
