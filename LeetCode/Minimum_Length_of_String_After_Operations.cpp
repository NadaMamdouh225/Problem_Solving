class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>map;
        int count=0;

        if(s.size()<3)return s.size();
        for(const auto& ch:s)
        {
            map[ch]++;
        }
        for(auto obj:map)
        {
            while(obj.second > 2)
            {
                obj.second -=2;
                count+=2;
            }
        }
        return s.size()-count;
    }
};
