// space -> O(1) 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ctn = 0;
        int ele = nums[0];
        for(auto &n: nums)
        {
            if (ctn == 0)   ele = n;
        
            if (n == ele)   ctn++;
            else    ctn--;
            
        }
        return ele;

    }
};
