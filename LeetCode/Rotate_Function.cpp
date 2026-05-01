class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f_0 = 0;
        int s_nums = 0;
        int len = nums.size();
        for(int i = 0; i<len; i++)
        {
            // calculate f[0]
            f_0 += i*nums[i];
            
            // calculate sum of nums
            s_nums +=nums[i];

        }  
        int max_n = f_0;
        int f_new = f_0;
        for(int i = 1; i<len; i++)
        {
            f_new += s_nums - (len* nums[len-i]);

            max_n = max(max_n, f_new);
        }
        return max_n;
        
    }
};
