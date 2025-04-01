class Solution {
public:
    long long dp[100001];
    long long solve(int i,vector<vector<int>>& questions)
    {
        //base case
        if(i >= questions.size()) return 0;
        if(dp[i]) return dp[i];
                    //skip              // take it
        return dp[i] = max(solve(i+1,questions), solve(i+1+questions[i][1],questions) + questions[i][0]);
        
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        return solve(0,questions);
    }
};
