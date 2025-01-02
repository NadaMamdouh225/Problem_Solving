#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool is_vowel(char letter) {
    static const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    return vowels.count(letter) > 0;
}
    std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {
        std:: vector<int>prefix_sum(words.size()+1,0);
        std::vector<int> ans;
        int count =0;

        for(int i =0;i<words.size();i++)
        {
            prefix_sum[i+1] = prefix_sum[i] + (is_vowel(words[i].front()) && is_vowel(words[i].back()) ? 1:0);
        }

        for(auto query:queries)
        {
            count = prefix_sum[query[1]+1] - prefix_sum[query[0]];
            ans.push_back(count);
            count = 0;
        }
        return ans;
    }
};
