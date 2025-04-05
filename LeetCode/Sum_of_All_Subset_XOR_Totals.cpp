class Solution {
public:
    int solve(int i,int currentXor,vector<int>& nums)
    {
        //base case
        if(i == nums.size()) return currentXor;
        // include nums[i] in the subset ---------- don't include nums[i]
        return solve(i+1,currentXor^nums[i],nums) + solve(i+1,currentXor,nums);

    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0, 0, nums);
    }
};
