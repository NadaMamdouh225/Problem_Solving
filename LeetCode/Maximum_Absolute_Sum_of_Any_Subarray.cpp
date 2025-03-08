#include <iostream>
#include <limits.h>
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int p = 0;
        int n = 0;
        int sum = 0;
        int max_num = 0;
        for(auto num:nums)
        {
            sum+=num;

            max_num = max(max_num, max(abs(sum-n),abs(sum-p)));
            p = max(p,sum);
            n = min(n,sum);
        } 
        return max_num;
    }
};
