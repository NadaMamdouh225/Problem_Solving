class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
     int l = 0;
     int r = nums.size()-1;
     int x = nums.size()-1;
     vector<int>ans(nums.size());
     while(l<=r)
     {
        if(abs(nums[r])>abs(nums[l]))
        {
            ans[x] = nums[r]*nums[r];
            x--;
            r--;
        }
        else
        {
            ans[x] = nums[l]*nums[l];
            x--;
            l++;
        }
     }
     return ans; 
    }
};
