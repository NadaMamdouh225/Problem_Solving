class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int>rem1, rem2;

        for(auto &n: nums)  {
            sum+=n;
            if(n%3 == 1)    rem1.push_back(n);
            else if(n%3 == 2)    rem2.push_back(n);
        }
        int option1 = 0, option2 = 0;
        
        sort(rem1.begin(),rem1.end());
        sort(rem2.begin(),rem2.end());

        if(sum % 3 == 0) return sum;
        else if(sum % 3 == 1)
        {
            option1 = rem1.empty() ? 0 : sum - *rem1.begin();
            
            if (rem2.size() >= 2) {
                auto it = rem2.begin();
                option2 = sum - (*it + *next(it));
            }


        }else if(sum % 3 == 2)
        {
            option1 = rem2.empty() ? 0 : sum - *rem2.begin();    
            if (rem1.size() >= 2) {
                auto it = rem1.begin();
                option2 = sum - (*it + *next(it)); 
            }
        
        }
        return max(option1, option2);
    }
};
