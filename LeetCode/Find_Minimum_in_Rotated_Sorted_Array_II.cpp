class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;
        while(l<r)
        {
            mid = l+(r-l)/2;
            if(nums[mid]>nums[r])
                l = mid+1;
            else if (nums[mid] == nums[r] && nums[mid] == nums[l])
                l +=1;
            else
                r = mid;
        }
        return nums[l];
    }
};
