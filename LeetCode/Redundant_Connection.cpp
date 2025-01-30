#include <numeric>

class Solution {
public:
    int parent[1001];
    int find_par(int node)
    {   
        //base case
        if(node == parent[node])return node;
        return parent[node] = find_par(parent[node]);
    }
    void join(int u, int v)
    {
        u = find_par(u);
        v = find_par(v);
        if(u != v)
        {
            parent[u] = v;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        iota(parent,parent+1001,0);

        for(auto x:edges)
        {
            if(find_par(x[0]) == find_par(x[1]))return x;
            join(x[0],x[1]);
            
        }
        return {};
    }
};
