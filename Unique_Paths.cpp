class Solution {
public:
    int Paths(int i, int j,vector<vector <int>> &dp) {
        int m = dp.size();
        int n = dp[0].size();
        if(i == m-1 && j == n-1)                ///reached ur goal
            return 1;
        if(i>m-1 || j>n-1 || i<0 || j<0)   ///out of range
            return 0;
        if(dp[i][j]!= -1)
            return dp[i][j];
        return dp[i][j] = Paths(i+1,j,dp)+Paths(i,j+1,dp);

    }
    int uniquePaths(int m , int n)
    {
        vector<vector <int>> dp(m,vector<int>(n,-1));
        return Paths(0,0,dp);
    }

};
