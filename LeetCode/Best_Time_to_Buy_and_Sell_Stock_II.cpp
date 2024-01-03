class Solution {
public:
    int profit = INT_MIN;

    int findMax(int index,bool buy,vector<int>& prices,vector<vector<int>>&dp)
    {
        // base case
        if(index >= prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        if (buy == 1)
        {
            profit = max( 0 + findMax(index+1,1,prices,dp) ,              // skip current day
                        findMax(index+1,0,prices,dp) - prices[index]);    // buy on the current day then proceed to next day
        }else
        {
            profit =max(0 + findMax(index+1,0,prices,dp),                 // skip current day
                        findMax(index+1,1,prices,dp) + prices[index]);    // sell on the current day then proceed to next day
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp (prices.size(),vector<int>(2,-1));
        return findMax(0,1,prices,dp);

    }
};
