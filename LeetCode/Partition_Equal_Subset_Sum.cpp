class Solution {
public:
    int dp[201][10001];
    bool solve(int i,int t,vector<int>& nums)
    {
        //base case
        if(t == 0) return true;
        if(i >= nums.size() || t<0) return false;
        if(dp[i][t] != -1) return dp[i][t];

        return dp[i][t] = solve(i+1,t - nums[i],nums) || solve(i+1,t,nums);
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        int sum =0;
        for(auto & n:nums){
            sum+=n;
        }
        if(sum % 2 == 1) return false;
        return solve(0, sum/2, nums);
    }
};
