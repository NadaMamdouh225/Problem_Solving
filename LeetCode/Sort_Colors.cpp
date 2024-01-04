class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count_colors(3, 0);
        for (int i = 0; i < nums.size(); i++) 
        {
            if(nums[i]==1)
                count_colors[1]++;
            else if(nums[i]==2)
                count_colors[2]++;
            else
                count_colors[0]++;
        }
        for (int i = 0; i < nums.size(); i++) 
        {
            if(count_colors[0]!=0)
            {
                nums[i] = 0;
                count_colors[0]--;
            }
            else if(count_colors[1]!=0)
            {
                nums[i] = 1;
                count_colors[1]--;
            }
            else if(count_colors[2]!=0)
            {
                nums[i] = 2;
                count_colors[2]--;
            }
        }
    }
};
