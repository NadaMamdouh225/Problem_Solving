class Solution {
public:

    int maximumSum(vector<int>& nums) {
        int maxsum = -1;
        map<int,vector<int>>mp;
        for(int i =0;i<nums.size();i++)
        {
            mp[sumdigits(nums[i])].push_back(nums[i]);
        }
        for(auto i = mp.rbegin(); i!= mp.rend(); i++)
        {
            if(i->second.size() >= 2)
            {
               sort(i->second.rbegin(), i->second.rend());
                
                maxsum = max(maxsum,i->second[0]+ i->second[1]);
                
            }
        }
        return maxsum;
    }

private:
    int sumdigits(int num)
    {
        int sum = 0;
        while(num>0)
        {
            sum += num%10;
            num = num/10; 
        }
        return sum;
    }
};
