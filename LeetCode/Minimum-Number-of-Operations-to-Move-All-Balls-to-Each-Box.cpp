class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        int sum =0;
        std::vector<int>res(boxes.size(),0);
        std::vector<int>ones_loc;

        for(int i = 0; i<boxes.size(); i++)
        {
            if(boxes[i]=='1') ones_loc.push_back(i);
        }

        for(int i=0;i<res.size();i++)
        {
            sum =0;
            for(auto one:ones_loc)
            {
                sum += abs(one-i);
            }
            res[i] = sum;
        }
        return res;
    }
};
