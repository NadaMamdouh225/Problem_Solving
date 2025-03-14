class Solution {
public:
    inline bool ok(int mid, vector<int>& candies, long long k)
    {
        for(auto &p : candies)
        {
            k-= p/mid;
        }
        return k<=0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1, r=*max_element(candies.begin(),candies.end()), curr=0, mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(ok(mid, candies, k))
            {
                curr = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return curr;
    }
};
