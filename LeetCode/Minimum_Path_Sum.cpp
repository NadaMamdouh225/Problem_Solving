class Solution {
public:
    int Memo(vector<vector<int>>& grid,vector<vector<int>>&dp,int r,int c)
    {
        //base case
        if(r == grid.size()-1 && c == grid[0].size()-1)
            return dp[r][c]=grid[r][c];
        //validation
        if(r>grid.size()-1 || c>grid[0].size()-1 || r<0 || c<0)
            return INT_MAX;
        if(dp[r][c] != -1)
            return dp[r][c];
        return dp[r][c] = grid[r][c] + min(Memo(grid,dp,r+1,c),Memo(grid,dp,r,c+1));
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));  
        return Memo(grid,dp,0,0); 
    }
};
