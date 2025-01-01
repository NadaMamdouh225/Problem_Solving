#include <iostream>

class Solution {
public:
    int maxScore(std::string s) {
        int count_ones = std::count(s.begin(),s.end(),'1');
        int s_length = s.size();
        int zeros =0;
        int ans =0;
        for(int i =0; i<s_length-1 ;i++)
        {
            if(s[i]== '0')
            {
                zeros++;
            }else count_ones--;
            ans = std::max(ans,count_ones+zeros);
        }
        return ans;
    }
};
