class Solution {
public:
    int MaxAmount(vector<int>& nums,vector<int>& dp,int n)
    {
        // base case
        if(n == 0 || n == 1)
            return nums[n];
        //validation
        if(n < 0)
            return 0;
        // check saved values
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = nums[n] + max(MaxAmount(nums, dp, n-2),MaxAmount(nums, dp, n-3));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return max(MaxAmount(nums,dp,n-1),MaxAmount(nums,dp,n-2));
    }
};
