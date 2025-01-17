class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result=0;
        for(auto obj:derived)
        {
            result ^=obj;
        }
        return (result == 0);
    }
};
