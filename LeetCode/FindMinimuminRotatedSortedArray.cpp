class Solution {
public:
    int findMin(vector<int>& nums) {
        int Min = nums[0];
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]>=Min) l = mid +1;
            else{
                Min = min(nums[mid],Min);
                r = mid -1;
            }
        }
        return Min;
    }
};
