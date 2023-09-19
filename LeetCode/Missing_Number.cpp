class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int i,n,ans;
    n = nums.size();
    sort(nums.begin(), nums.end());
    for(i=0;i<n;i++)
    {
        if(i!= nums[i])
        {
           ans = i;
            break;
        }
    }
        return ans;

    }
};
