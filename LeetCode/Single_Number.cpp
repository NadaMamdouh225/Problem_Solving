class Solution {
public:
    int singleNumber(vector<int>& nums) {
    map<int,int>Map;
    for(auto i :nums)
    {
        Map[i]++;
    }
    for(auto i = Map.begin(); i!=Map.end() ;++i)
    {
        if(i->second == 1)
        {
            return (i->first);
            
        }
    }
    return 0;

    }
};
