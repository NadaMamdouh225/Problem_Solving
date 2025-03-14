class Solution {
public:
    bool ok(int mid, vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size();
        int cnt =0;
        vector<int>v(n+1);
        for(int i =0; i<mid; i++)
        {
            int l = queries[i][0], r =queries[i][1] , val = queries[i][2];
            v[l] += val;
            v[r+1] += -val;
        }
        for(int i =0; i<n; i++)
        {
            v[i+1] += v[i];
            cnt += (nums[i]-v[i])<=0;
        }
        return cnt == n;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l =0, r = queries.size() , cur=-1, mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(ok(mid, nums, queries))
            {
                cur = mid;
                r = mid -1;
            }else l = mid +1; 
        }
        return cur;
    }
};
