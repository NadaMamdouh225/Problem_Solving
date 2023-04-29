class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int l = 1;
        long long int r = num/2;
        long long int mid = (l+r)/2;
        long long int n_square = mid *mid; 
        if(num == 1)
        {
            return true;
        }
        while(l<=r)
        {
            if(n_square == num)
            {
                return true;
            }else if(n_square>num)
            {
                r = mid -1;
            }
            else
            {
                l = mid +1;
            }
            mid = (l+r)/2;
            n_square = mid *mid;
        }
        return false;
    }
};
