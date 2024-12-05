#include<climits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int currentsum = 0;
        int maxsum = INT_MIN;
        for(auto number:nums)
        {
            currentsum += number;
            if(currentsum > maxsum) maxsum = currentsum;
            if(currentsum<0) currentsum = 0;
        
        }
        return maxsum;
    }
};
