class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     sort(piles.begin(),piles.end());
     int l = 1;
     int r = piles[piles.size()-1];
     int k;
     long int h_new = 0;
    while(l<=r)
    {
        k = (l+r)/2;
        for(auto i: piles)
        {
            h_new+=ceil((double)i/k);
        }
        if(h_new<=h) r = k-1;
        else l = k + 1;
        h_new = 0;
    }
    return l; 
    }
};
