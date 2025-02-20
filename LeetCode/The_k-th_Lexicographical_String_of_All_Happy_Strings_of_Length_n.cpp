class Solution {
public:
    vector<string>v;
    void solve(int n, string s)
    {
        // base case
        if(n == 0)
        {
            v.push_back(s);
            return;
        }
        for(char ch = 'a';ch <='c';ch++)
        {
            // skip not happy strings
            if(s.size() && s.back() == ch) continue;
            s.push_back(ch);   // do
            solve(n-1,s);      // recurrce
            s.pop_back();       //undo

        }
    }
    string getHappyString(int n, int k) {
        solve(n,"");
        return v.size()>=k? v[k-1]:"";
        
    }
};
