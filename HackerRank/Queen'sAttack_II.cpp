#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

#include <vector>
#include <algorithm>
using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int count = 0;
    int up = n - r_q;
    int down = r_q - 1;
    int right = n - c_q;
    int left = c_q - 1;
    int upRight = min(up, right);
    int upLeft = min(up, left);
    int downRight = min(down, right);
    int downLeft = min(down, left);
    
    // Iterate through obstacles and update counts
    for (int i = 0; i < k; i++) {
        int r_obst = obstacles[i][0];
        int c_obst = obstacles[i][1];
    
         // Right and Left blocks
        if(r_obst == r_q) 
        {
            if(c_obst>c_q) right = min(right,c_obst-c_q-1);
            else if(c_obst<c_q)left = min(left,c_q-c_obst-1);
        }
         // Up and Down blocks
        if(c_obst == c_q) 
        {
            if(r_obst>r_q) up = min(up,r_obst-r_q-1);
            else if(r_obst<r_q)down = min(down,r_q-r_obst-1);
        }
            // Diagonal blocks
         if (abs(r_obst - r_q) == abs(c_obst - c_q)) {
            if (r_obst > r_q && c_obst > c_q) {
                upRight = min(upRight, r_obst - r_q - 1); 
            } else if (r_obst > r_q && c_obst < c_q) {
                upLeft = min(upLeft, r_obst - r_q - 1); 
            } else if (r_obst < r_q && c_obst > c_q) {
                downRight = min(downRight, r_q - r_obst - 1); 
            } else if (r_obst < r_q && c_obst < c_q) {
                downLeft = min(downLeft, r_q - r_obst - 1);
            }
        }
    }

    count = up + down + right + left + upRight + upLeft + downRight + downLeft;

    return count;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
