class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if(coordinates[0]%2== 1 && coordinates[1]%2 == 0)
        {
            return true;
        }else if(coordinates[0]%2== 0 && coordinates[1]%2 == 1)
        {
            return true;
        }
        return false;
    }
};
