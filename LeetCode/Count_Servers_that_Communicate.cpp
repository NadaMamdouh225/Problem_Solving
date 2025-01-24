class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int res =0;
        vector<int>count_r(r);
        vector<int>count_c(c);
        for(int i =0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j])
                {
                    count_r[i]++;
                    count_c[j]++;
                }
            }
        }
        for(int i =0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] && (count_r[i]>1||count_c[j]>1))
                {
                    res++;
                }
            }
        }
        
        return res;
    }
};
