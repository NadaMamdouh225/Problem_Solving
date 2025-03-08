class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int min_ = INT_MAX;
        int count_W = 0;
        for(int i=0;i<k;i++)
        {
            if(blocks[i] == 'W')count_W++;
        }
        min_ = min(min_,count_W);
        
          // Sliding window
        for(int i =k;i<blocks.size();i++)
        {
            if(blocks[i-k] == 'W') count_W--;
            if(blocks[i] == 'W') count_W++;
            min_ = min(min_,count_W);
        }
        return min_;
    }
};
