class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int first = 0; 
        int last = n-1;
        int mid = (first + last)/2;
        int ans;
        while(first<=last)
        {
            if(target > nums[mid])
            {
                first = mid+1;
            }else if(target < nums[mid])
            {
                last = mid-1;
            }
            else if(target == nums[mid])
            {
                ans = mid;
                break;
            }
            else
            {
                ans = -1;
            }

            mid = (first + last)/2;

        }
        return ans;
    }
};

