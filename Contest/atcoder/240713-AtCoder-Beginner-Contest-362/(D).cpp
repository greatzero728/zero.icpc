#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using pIi = pair<INT, int>;

const int NN = 202020;

vector<pii> adj[NN];

int wei[NN];
INT d[NN];

priority_queue<pIi, vector<pIi>, greater<pIi> > pq;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", wei + i);
	while(m--) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	for(int i = 1; i <= n; i++) d[i] = 1e17;
	d[1] = wei[1];
	
	pq.push({d[1], 1});
	while(!pq.empty()) {
		pIi U = pq.top(); pq.pop();
		int u = U.y;
		if(U.x > d[u]) continue;
		for(pii p : adj[u]) {
			int v = p.x, w = p.y;
			if(d[v] > d[u] + w + wei[v]) {
				pq.push({d[v] = d[u] + w + wei[v], v});
			}
		}
	}
	
	for(int i = 2; i <= n; i++) printf("%lld ", d[i]);
	return 0;
}
