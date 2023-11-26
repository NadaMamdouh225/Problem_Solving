class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>output;
        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string oldstr = strs[i];
            sort(oldstr.begin(), oldstr.end());
            mp[oldstr].push_back(strs[i]);
        }
        for(auto i:mp)
            output.push_back(i.second);
        return output;
    }
};
