class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long int sum_l = 0;
        int count_split = 0;
        int j = nums.size()-1;
        vector<long int> sum_v_l(nums.size(),0);
        for(int i=0; i<nums.size();i++)
        {
            sum_l+=nums[i];
            sum_v_l[i] = sum_l;
        }
        
        for(int i =0; i<nums.size()-1; i++)
        {
            
            if(sum_v_l[i] >= (sum_v_l[nums.size()-1]-sum_v_l[i]))
            {
                count_split++;
            }
        }
        return count_split;
    }
};
