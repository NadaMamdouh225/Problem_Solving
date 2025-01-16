class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int result=0;
        if((len1 == 1) && (len2 == 1)) return (nums1[0]^nums2[0]);
        if(len1 == len2) return 0;
        if((len1%2 ==1) && (len2%2 ==1))
        {
            result = xor_num(nums2);
            result ^= xor_num(nums1);
        }
        else if(len1 %2 ==1) result = xor_num(nums2);
        else if(len2 %2 ==1) result = xor_num(nums1);

        return result;
    }
private:
    int xor_num(vector<int>& nums)
    {  
        int result=0;
        for(auto n:nums)
        {
            result ^=n;
        }
        return result;
    }
};
