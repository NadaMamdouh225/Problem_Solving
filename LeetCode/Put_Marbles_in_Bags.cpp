class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n =weights.size();
        long long res=0;
        vector<int>v;
        v.reserve(n-1);
        for(int i =1; i <n ;i++)
        {
            v.push_back(weights[i]+weights[i-1]);
        }
        sort(v.begin(),v.end());
        for(int i =0;i<k-1;i++) res += v[n-2-i] - v[i];
        return res;
    }
};
