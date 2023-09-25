
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>sol;
        unordered_map<int, int>m;
        for (auto i : nums)
        {
            m[i] = -1;
        }
        for (int i = 1;i <= nums.size();i++)
        {
            if (m.find(i) == m.end())
            {
                sol.push_back(i);
            }
        }
        return sol;
    }
};


int main() {

    // Test
    Solution obj;
    vector<int> v = {4,3,2,7,8,2,3,1};
    vector <int> ans = obj.findDisappearedNumbers(v);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    
    return 0;
}
