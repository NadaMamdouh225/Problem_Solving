class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd, even, sum=0;
        int count =0;
        for(auto n:arr)
        {
            sum+=n;
            if(sum%2==0){  even++;
                count += odd;
            }
            else{
                odd++ ;
                count = count + 1 + even;
            }
            if(count>=1000000007)count-=1000000007;
            
        }
        return count;
    }
};
