class Solution {

public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, j = 1;
        int cnt = 1;
        int n = nums.size();
        while(j<n)
        {
            if((nums[j] == nums[j-1]))  cnt++;
            else    cnt=1;

            if(cnt<3)
            {
                nums[i] = nums[j];
                i++;
            
            }
            j++;
        }
        return i;
    }
};
