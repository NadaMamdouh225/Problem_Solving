class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool flag_row = false;
        bool flag_col = false;
        // Check if the first row needs to be zeroed out
        for (int j = 0; j < cols; j++) {
            if(matrix[0][j] == 0)
            {
                flag_row = true;
            }
        }
        // Check if the first col needs to be zeroed out
        for (int i = 0; i < rows; i++) {
            if(matrix[i][0] == 0)
            {
                flag_col = true;
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // set first cell of this row to zero
                    matrix[0][j] = 0; // set first cell of this col to zero
                }
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[0][j] == 0) // set all cols to zero
                {
                    matrix[i][j] = 0;
                }
                
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0) // set all rows to zero
                {
                    matrix[i][j] = 0;
                }       
            }
        }
        if(flag_row)
        {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }
        if(flag_col)
        {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
