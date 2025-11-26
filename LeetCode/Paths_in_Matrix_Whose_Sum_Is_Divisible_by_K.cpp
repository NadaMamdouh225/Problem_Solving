class Solution {
public:
    int mod = 1e9+7;
    int n,m, gk;
    vector<vector<vector<int>>> memo;
    int paths(int i, int j, int remainder, vector<vector<int>>& grid)
    {  
        // Base case: Reached the goal
        if(i == m-1 && j == n-1)
                return ((remainder + grid[i][j]))%gk == 0?  1 :  0;
        
        // Base case: Out of Bounds
        if(i>m-1 || j>n-1 || i<0 || j<0)    return 0;
        
        // Memoization check
        if(memo[i][j][remainder] != -1)    return memo[i][j][remainder];

        // Recursive Relation
        int down = paths(i+1, j, (remainder + grid[i][j])%gk, grid);
        int right = paths(i, j+1, (remainder + grid[i][j])%gk, grid);
        return memo[i][j][remainder] = (down + right) % mod;

    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();   
        gk = k;     
        memo.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return paths(0, 0, 0, grid);
    }

};

