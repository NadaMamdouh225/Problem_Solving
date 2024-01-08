class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool searchLastPos) {
        int index = -1;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                index = mid;
                if (searchLastPos)
                {
                    l = mid + 1;
                }else
                {
                    r = mid - 1;
                }
            } else if (target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return index;
    }
    vector<int>searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(binarySearch(nums,target,0));
        result.push_back(binarySearch(nums,target,1));
        return result;
    }
};
