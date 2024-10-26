#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

pii p[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d %d", &p[i].x, &p[i].y);
    sort(p + 1, p + n + 1, [&](pii a, pii b) {
        return a.y < b.y;
    });
    
    INT ans = (INT)(1 + m) * m >> 1;
    
    int mx = 0;
    for(int R = 1, i = 1; R <= m; R++) {
        for(; i <= n && p[i].y <= R; i++) mx = max(mx, p[i].x);
        if(mx) ans -= mx;
    }
    cout<<ans<<endl;
	return 0;
}
