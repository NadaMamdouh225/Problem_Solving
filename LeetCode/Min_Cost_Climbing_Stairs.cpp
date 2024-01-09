class Solution {
public:
    int step(vector<int>& cost,int n,vector<int>& dp)
    {
        //base case
        if(n == 0 || n == 1)
            return cost[n];
        // out of boundry
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];

        return dp[n]= cost[n]+min(step(cost,n-1,dp),step(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(step(cost,n-1,dp),step(cost,n-2,dp));
    }
};
