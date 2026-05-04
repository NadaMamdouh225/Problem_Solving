class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        
        for(int shift = 0; shift < s.size(); shift++)
        {
            bool match = true;

            for (int i = 0; i < s.size(); i++) {
                if(s[(i+shift)% s.size()] != goal[i])
                {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }
};
