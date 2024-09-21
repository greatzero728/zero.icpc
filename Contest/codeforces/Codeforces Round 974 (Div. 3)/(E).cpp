#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using pIi = pair<INT, int>;

const int NN = 202020;
const INT inf = 1e15;

vector<pii> adj[NN];
bool flag[NN];
INT d[NN], mx[NN], tmp[NN];

int n;
#define pq priority_queue<pIi, vector<pIi>, greater<pIi> >
pq q;

void bfs(int st) {
    for(int i = 1; i <= n; i++) d[i] = inf;
    d[st] = 0;
    q.push({d[st], st});
    
    while(!q.empty()) {
        pIi p = q.top(); q.pop();
        int u = p.y;
        if(p.x > d[u]) continue;
        for(pii cc: adj[u]) {
            int v = cc.x, w = cc.y;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++) tmp[i] = d[i];
    
    for(int i = 1; i <= n; i++) {
        d[i] = inf;
        if(flag[i]) {
            d[i] = tmp[i];
            q.push({d[i], i});
        }
    }
    while(!q.empty()) {
        pIi p = q.top(); q.pop();
        int u = p.y;
        if(p.x > d[u]) continue;
        for(pii cc: adj[u]) {
            int v = cc.x, w = cc.y / 2;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++) mx[i] = max(mx[i], min(tmp[i], d[i]));
}

INT solve() {
    int m, h; scanf("%d %d %d", &n, &m, &h);
    for(int i = 1; i <= n; i++) {
        flag[i] = mx[i] = 0;
        adj[i].clear();
    }
    while(h--) {
        int x; scanf("%d", &x);
        flag[x] = 1;
    }
    while(m--) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    bfs(1), bfs(n);
    INT ans = *min_element(mx + 1, mx + n + 1);
    if(ans < inf) return ans;
    return -1;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) printf("%I64d\n", solve());
}