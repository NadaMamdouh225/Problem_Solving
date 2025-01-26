#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        // connect index with value
        //pair<value, index>
        std::vector<std::pair<int,int>> v;
        for(int i =0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }

        std::sort(v.begin(),v.end());
        // create groups 
        std::vector< std::vector<std::pair<int,int>>>components;
        components.push_back({v[0]});
        for(int i=1; i<n; i++)
        {
            if(v[i].first - v[i-1].first <= limit ) components.back().push_back(v[i]);
            else components.push_back({v[i]});
            
        }
        // sort indecies
        for( auto c:components)
        {
            std::vector<int>idx;
            for(auto it: c) idx.push_back(it.second);
            std::sort(idx.begin(), idx.end());
            for(int i=0;i<idx.size();i++) nums[idx[i]] = c[i].first;
        }
        return nums;
    }
};
