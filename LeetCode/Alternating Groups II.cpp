class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;
        int window_size = 1;
        for(int i=1;i<(n+k-1);i++)
        {
            window_size = (colors[i>=n? i-n:i] != colors[(i-1)>=n ? (i-1)-n:(i-1)])? window_size+1 :1;
            ans += (window_size >= k);
            
        }

        return ans;
    }
};
