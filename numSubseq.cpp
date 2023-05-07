class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r = n-1;
        int ans = 0;
        int modulo = (int)((1e9) + 7);
        sort(nums.begin(),nums.end());
        vector<int>pow(n+1,1);
        for(int i=1;i<n;i++)
        {
            pow[i]=pow[i-1]*2 %modulo;
        }
        while(l<=r)
        {
            if(nums[l]+nums[r] > target)
            {
                r--;
            }
            else
            {
                ans = (ans + pow[r-l])%modulo;
                l++;
            }
        }
        return ans;
        
    }
};
