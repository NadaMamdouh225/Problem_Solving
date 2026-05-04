class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string decodedText;
        int counter = 0;
        int len = encodedText.length();
        int cols = len / rows;
          if (rows == 1) {
            // just remove trailing spaces
            string result = encodedText;
            while (!result.empty() && result.back() == ' ')
                result.pop_back();
            return result;
        }

        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                int index = r * cols + (c + r); // compute linear index
                if (index < len) {
                    decodedText.push_back(encodedText[index]);
                }
            }
        }
        
        while (!decodedText.empty() && decodedText.back() == ' ') {
            decodedText.pop_back();
        }

        return decodedText;
    }
};
