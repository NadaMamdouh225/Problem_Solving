class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k%2 == 0 || k%5 == 0)
            return -1;
        int i = 0;
        int n = 1;
        for(; i<=k ;i++)
        {
            if(n%k)
                n = ((n*10) +1)%k;
            else
                break;
        }
        return i+1;
    }
};
