class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res =0 , i_max=nums[0],dif =0;
        for(int k=2; k<nums.size(); k++)
        {
            dif = max(dif,(long long)i_max-nums[k-1]); 
           
            i_max = max(i_max,(long long)nums[k-1]);
    
            res = max(res,(long long)dif*nums[k]);
         
        }

        return res;
    }
};
