class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result;
        
        for(int i =0;i<=n;i++)
        {
            int count =0;
            int num =i;
            while(num)
            {
                num = num & (num-1);
                count++;
            }
            result.push_back(count);
        }
        return result;
    }
};
