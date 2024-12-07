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
    for(int i = 1; i <= m; i++) scanf("%d", &p[i].x);
    for(int i = 1; i <= m; i++) scanf("%d", &p[i].y);
    sort(p + 1, p + m + 1);
    
    if(p[1].x != 1) {puts("-1"); return 0;}
    
    INT sum = 0;
    for(int i = 1; i <= m; i++) {
        sum += p[i].y;
    }
    if(sum != n) {puts("-1"); return 0;}
    
    INT ans = 0;
    p[m + 1].x = n + 1;
    for(int i = 1; i <= m; i++) {
        int len = p[i + 1].x - p[i].x - 1;
        if(p[i].y < len + 1) {puts("-1"); return 0;}
        int cnt = p[i].y - 1;
        ans += (INT)(len + 1) * len >> 1;
        ans += (INT)(len + 1) * (cnt - len);
        p[i + 1].y += cnt - len;
    }
    cout<<ans<<endl;
	return 0;
}
