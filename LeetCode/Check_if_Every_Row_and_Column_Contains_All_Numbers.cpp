class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_map<int, int> row_mp;
        unordered_map<int, int> col_mp;
        // validate rows and cols
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                    row_mp[matrix[i][j]]++;
                    col_mp[matrix[j][i]]++;
                    if (row_mp[matrix[i][j]] > 1 || col_mp[matrix[j][i]] > 1)
                        return false;
                }
                row_mp.clear();
                col_mp.clear();
            }
            
        return true;
    }
};
