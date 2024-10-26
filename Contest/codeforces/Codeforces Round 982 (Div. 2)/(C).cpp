#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pIi = pair<INT, int>;

const int NN = 303030;

int id[NN];
INT a[NN];
INT prelen[NN], len[NN];

INT solve() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", a + i);
        prelen[i] = i - 1 + a[i];
        len[i] = i - 1 + a[i] + i - 1;
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [&](int u, int v) {
        if(prelen[u] == prelen[v]) return a[u] < a[v];
        return prelen[u] < prelen[v];
    });
    
    set<INT> s;
    s.insert(n);
    
    INT mx = n;
    for(int i = 1; i <= n; i++) {
        int u = id[i];
        if(s.find(prelen[u]) != s.end()) {
            s.insert(len[u]), mx = max(mx, len[u]);
        }
    }
    return mx;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int t; scanf("%d", &t);
    while(t--) printf("%I64d\n", solve());
	return 0;
}
