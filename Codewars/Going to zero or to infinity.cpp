#include <vector>

using namespace std;

class Suite
{
public:
    static double fac_dp(int n, int l, vector<double> &dp)
    {
        if(n < l)
            return 1;
        if(dp[n] != -1)
            return dp[n];

        return dp[n] = n * fac_dp(n - 1, l, dp);
    }

    static double fac(int n, int l)
    {
        l = n - l;
        vector<double> dp(n + 1, -1);
        return fac_dp(n, l, dp);
    }

    static double going(int n)
    {
        double sum = 1;
        int j = 0;
        for(int i = 0; i < n - 1; i++)
        {
            sum += 1 / fac(n, j);
            j++;
        }
        return sum;
    }
};
