class Solution {
public:
    bool safe_node_dfs(int node,vector<vector<int>>& graph, vector<bool>& visited,vector<bool>& terminal_node)
    {
        // base case
        if(terminal_node[node])return true;
        if(visited[node]) return false;
        // mark this node as visited
        visited[node] = 1;
        for(auto child: graph[node])
        {
            if(safe_node_dfs(child,graph,visited,terminal_node)== 0)return false;
        }
        return terminal_node[node] = true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>terminal_node(n);
        for(int i=0; i<n; i++)
        {
            if(!graph[i].size()) terminal_node[i] = 1;
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            vector<bool>visited(n);
            if(safe_node_dfs(i,graph,visited,terminal_node))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
