class Solution {
public:
    int countPrefixSuffixPairs(std::vector<std::string>& words) {
        int count = 0;
        for(int i =0; i<words.size(); i++)
        {
            for(int j =i+1;j<words.size();j++)
            {
                if(isPrefixAndSuffix(words[i],words[j]))
                {
                    count++;
                }
            }
        }
        
        return count;
    }

private:
     bool isPrefixAndSuffix(const std::string& word1, const std::string& word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        if (len1 > len2) return false;

        std::string prefix = word2.substr(0, len1);
        std::string suffix = word2.substr(len2 - len1);

        return (prefix == word1 && suffix == word1);
    }
};
