class Solution {
public:
    int prefixCount(std::vector<std::string>& words, std::string pref) {
        int pref_len = pref.size();
        int count =0;
        for(const auto& word:words)
        {
            std::string prefix = word.substr(0,pref_len);
            if(prefix == pref)
            {
                count++;
            }
        }
        return count;
    }
};
