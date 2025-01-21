class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long int top_sum =0;
        long long int bottom_sum = 0;
        long long int res = LLONG_MAX;
        for (auto cell:grid[0]) top_sum+=cell;

        for(int i=0;i<grid[0].size();i++)
        {
            top_sum -=grid[0][i];
            res = min(res,max(top_sum,bottom_sum));
            bottom_sum +=grid[1][i];
        }
        return res;
    }
};
