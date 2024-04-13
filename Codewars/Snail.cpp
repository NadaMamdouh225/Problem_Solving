vector<int> snail(const vector<vector<int>> &snail_map)
{
    vector<int> result;
    int n = snail_map.size();
    int v = n;

    if (snail_map[0].size() == 0)
        return result;

    for (int j = 0; j < v / 2; j++)
    {
        // first row
        for (int i = j; i < n - 1; i++)
            result.push_back(snail_map[j][i]);

        // last col
        for (int i = j; i < n - 1; i++)
            result.push_back(snail_map[i][n - 1]);

        // last row
        for (int i = n - 1; i > j; i--)
            result.push_back(snail_map[n - 1][i]);

        // first col
        for (int i = n - 1; i > j; i--)
            result.push_back(snail_map[i][j]);

        n -= 1;
    }

    if (v % 2 == 1)
        result.push_back(snail_map[v / 2][v / 2]);

    return result;
}
