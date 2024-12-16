#include <bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pIi = pair<INT, int>;

#define pq priority_queue<pIi, vector<pIi>, greater<pIi> >

const int NN = 101010;

vector<int> adj[NN];
INT dx[NN], dy[NN], dz[NN];
int n, m;

void get_shortest_path(long long *d, int st, int c) {
    for(int i = 1; i <= n; i++) d[i] = 1e18;
    
    d[st] = 0;
    pq q;
    q.push({d[st], st});
    while(!q.empty()) {
        pIi p = q.top(); q.pop();
        int u = p.y;
        if(d[u] < p.x) continue;
        for(int v : adj[u]) {
            if(d[v] > d[u] + c) {
                q.push({d[v] = d[u] + c, v});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int t1, t2, x, y, z;
    scanf("%d %d %d %d %d", &t1, &t2, &x, &y, &z);
    while(m--) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u].push_back(v), adj[v].push_back(u);
    }
    get_shortest_path(dx, x, t2);
    get_shortest_path(dy, y, t2);
    get_shortest_path(dz, z, t1);
    
    INT ans = dx[z] + dy[z];
    for(int c = 1; c <= n; c++) {
        ans = min(ans, dx[c] + dy[c] + dz[c]);
    }
    cout<<ans<<endl;
}
