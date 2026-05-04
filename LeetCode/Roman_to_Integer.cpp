#include <map>

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        int l = s.size()-1;
        int sum = m.at(s[l]);

        for(int i = l-1; i>=0 ;i--)
        {
            if(m.at(s[i]) < m.at(s[i+1]))     sum +=  -m.at(s[i]);
            else   sum +=  m.at(s[i]);
            
        }
        return sum ;
    }
};
