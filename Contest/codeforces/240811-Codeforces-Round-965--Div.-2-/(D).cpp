#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int U[NN], V[NN], d[NN];
vector<int> adj[NN];

#define PQ priority_queue<pii, vector<pii>, greater<pii> >

int num[NN];

void solve() {
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 1; i < n; i++) {
		adj[i].clear();
		adj[i].push_back(i + 1);
		d[i] = NN;
	}
	
	for(int i = m; i--; ) {
		scanf("%d %d", U + i, V + i);
		adj[U[i]].push_back(V[i]);
	}
	
	PQ q;
	q.push({d[1] = 0, 1});
	while(!q.empty()) {
		pii p = q.top(); q.pop();
		int u = p.y;
		if(p.x > d[u]) continue;
		for(int v : adj[u]) {
			if(d[v] > d[u] + 1) {
				q.push({d[v] = d[u] + 1, v});
			}
		}
	}
	
	for(int i = 1; i <= n; i++) num[i] = 0;
	for(int i = m; i--; ) {
		int st = U[i], ed = V[i];
		int L = st + 1, R = ed - d[st] - 2;
		if(L <= R) num[L]++, num[R + 1]--;
	}
	for(int i = 1; i < n; i++) {
		num[i] += num[i - 1];
		if(num[i]) putchar('0');
		else putchar('1');
	}
	puts("");
	return ;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}