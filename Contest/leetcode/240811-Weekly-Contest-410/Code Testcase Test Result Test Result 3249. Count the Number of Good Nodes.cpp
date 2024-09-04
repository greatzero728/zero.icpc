class Solution {
public:
    static const int NN = 101010;
    vector<int> adj[NN];
    int ans;
    int dfs(int u, int f = -1) {
        int sz = 1, mn = -1, mx = -1;
        for(int v : adj[u]) if(v != f) {
            int s = dfs(v, u);
            if(!~mn) mn = mx = s;
            else mn = min(mn, s), mx = max(mx, s);
            sz += s;
        }
        if(mn == mx) ans++;
        return sz;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        for(vector<int> p:  edges) {
            int u = p[0], v = p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0);
        return ans;
    }
};
