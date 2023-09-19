class Solution {
public:
    int arrangeCoins(int n) {
        unsigned long long int l = 1;
        unsigned long long int r = n;
        unsigned long long int mid = (r+l)/2;
        unsigned long long int coins_in_completed_rows = (mid*(mid+1))/2;
        cout<<"rows:"<<coins_in_completed_rows<<endl;
        while(l<=r)
        {
            
            if(coins_in_completed_rows == n)
            {
                return mid;
            }else if(coins_in_completed_rows > n)
            {
                r = mid -1;
            }
            else{
                l = mid +1;
            }
            mid = (r+l)/2;
            coins_in_completed_rows = (mid*(mid+1))/2;
        }
                return l-1;
    }
};
