class Solution{
public:

    int get_fib(int num,int dp[])
    {

       for(int i=0;i<=num;i++)
       {
          dp[i]= -1;
       }
       if(num <2)
        return num;

       if(dp[num] != -1)
        return dp[num];
    return dp[num] = get_fib(num-1,dp) + get_fib(num-2,dp) ;

    }


    int fib(int num) {
         int *dp=new int[num+1];
        return get_fib(num,dp);
    }
};
