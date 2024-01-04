class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        unordered_map <int,int>recordMap;
        for(auto i:nums)
        {
            recordMap[i]++;
        }
        for(auto i = recordMap.begin();i!=recordMap.end();i++)
        {
            if(i->second == 2)
            {
                result.push_back(i->first);
            }
        }
        return result;
    }
};
