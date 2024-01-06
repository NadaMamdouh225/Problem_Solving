class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row_mp;
        unordered_map<char, int> col_mp;
        unordered_map<char, int> subgrid_mp;
        // validate rows and cols
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    row_mp[board[i][j]]++;
                }
                if (board[j][i] != '.') {
                    col_mp[board[j][i]]++;
                }
                if (row_mp[board[i][j]] > 1 || col_mp[board[j][i]] > 1)
                    return false;
            }
            row_mp.clear();
            col_mp.clear();
        }
        // validate subgrids
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board[0].size(); j += 3) {
                for (int k = i; k < i + 3; k++) {
                    for (int z = j; z < j + 3; z++) {
                        if (board[k][z] != '.') {
                            subgrid_mp[board[k][z]]++;
                        }
                        if (subgrid_mp[board[k][z]] > 1)
                            return false;
                    }
                }
                subgrid_mp.clear();
            }
        }
        return true;
    }
};
