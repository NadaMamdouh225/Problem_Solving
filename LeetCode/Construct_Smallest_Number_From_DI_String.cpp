class Solution {
public:
    string ans;
    vector<bool>vis;
    bool solve(int idx, string& pattern)
    {
        //base case
        if(idx == pattern.size()) return ans.size() == idx+1;

        for(char ch = '1';ch <='9';ch++)
        {
            //corner cases
            if(vis[ch -'1']) continue;
            if(pattern[idx] == 'I' && ch <= ans.back())continue;
            if(pattern[idx] == 'D' && ch >= ans.back())continue;

            ans.push_back(ch); vis[ch-'1'] = true;  //do
            if(solve(idx+1,pattern))return true; //recurrence
            ans.pop_back(); vis[ch-'1'] = false; // undo
        }
        return false;

    }
    string smallestNumber(string pattern) {
        ans.clear();
        vis.assign(9, false); 
       for(char ch = '1';ch <='9';ch++)
        {
            ans.push_back(ch); vis[ch-'1'] = true;  //do
            if(solve(0,pattern))return ans; //recurrence
            ans.pop_back(); vis[ch-'1'] = false; // undo
        }
        return "-1";
    }
};
