#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020, MM = NN << 1;

int p[NN];
char s[NN];

int ls[MM], rs[MM], nn;
int a[MM], b[MM], c[MM], d[MM], e[MM], f[MM];
bool can[MM];
int sz[MM];
int l, r;

#define mid (L + R >> 1)

void push_up(int u, int L, int R) {
    if(s[mid - 1] != 'R' && s[mid] != 'L') { //two
        sz[u] = sz[ls[u]] + sz[rs[u]];
        
        a[u] = a[ls[u]];
        b[u] = b[ls[u]];
        if(sz[ls[u]] == 1) {
            if(sz[rs[u]] == 1);
            else c[u] = a[rs[u]];
        }
        else if(sz[ls[u]] == 2) c[u] = e[ls[u]];
        else c[u] = c[ls[u]];
        
        if(sz[rs[u]] == 1) {
            if(sz[ls[u]] == 1);
            else d[u] = f[ls[u]];
        }
        else if(sz[rs[u]] == 2) d[u] = b[rs[u]];
        else d[u] = d[rs[u]];
        e[u] = e[rs[u]];
        f[u] = f[rs[u]];
        
        if(can[ls[u]] && can[rs[u]]) {
            can[u] = f[ls[u]] < a[rs[u]];
        }
        else can[u] = 0;
    }
    else {//one
        sz[u] = sz[ls[u]] + sz[rs[u]] - 1;
        
        int mn = min(e[ls[u]], a[rs[u]]);
        int mx = max(f[ls[u]], b[rs[u]]);
        
        if(sz[ls[u]] == 1) a[u] = mn, b[u] = mx;
        else a[u] = a[ls[u]], b[u] = b[ls[u]];
        
        if(sz[ls[u]] == 1) c[u] = c[rs[u]];
        else if(sz[ls[u]] == 2) c[u] = mn;
        else c[u] = c[ls[u]];
        
        if(sz[rs[u]] == 1) d[u] = d[ls[u]];
        else if(sz[rs[u]] == 2) d[u] = mx;
        else d[u] = d[rs[u]];
        
        if(sz[rs[u]] == 1) e[u] = mn, f[u] = mx;
        else e[u] = e[rs[u]], f[u] = f[rs[u]];
        
        if(can[ls[u]] && can[rs[u]]) {
            if(sz[ls[u]] == 1) {
                if(sz[rs[u]] == 1) can[u] = 1;
                else if(sz[rs[u]] == 2) {
                    can[u] = mx < e[rs[u]];
                }
                else can[u] = mx < c[rs[u]];
            }
            else if(sz[ls[u]] == 2) {
                if(b[ls[u]] < mn) {
                    if(sz[rs[u]] == 1) can[u] = 1;
                    else if(sz[rs[u]] == 2) {
                        can[u] = mx < e[rs[u]];
                    }
                    else can[u] = mx < c[rs[u]];
                }
                else can[u] = 0;
            }
            else {
                if(d[ls[u]] < mn) {
                    if(sz[rs[u]] == 1) can[u] = 1;
                    else if(sz[rs[u]] == 2) {
                        can[u] = mx < e[rs[u]];
                    }
                    else can[u] = mx < c[rs[u]];
                }
                else can[u] = 0;
            }
        }
        else can[u] = 0;
    }
}

void replace(int u, int L) {
    can[u] = 1, sz[u] = 1;
    a[u] = b[u] = e[u] = f[u] = p[L];
}

int build(int L, int R) {
    int u = nn++;
    if(R - L == 1) replace(u, L);
    else {
        ls[u] = build(L, mid);
        rs[u] = build(mid, R);
        push_up(u, L, R);
    }
    return u;
}

void update(int u, int L, int R) {
    if(l <= L && R <= r) replace(u, L);
    else {
        if(l < mid) update(ls[u], L, mid);
        if(mid < r) update(rs[u], mid, R);
        push_up(u, L, R);
    }
}

void solve() {
    int n, q; scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d", p + i);
    scanf("%s", s + 1);
    
    nn = 0, build(1, n + 1);
    while(q--) {
        scanf("%d", &l), r = l + 1;
        if(s[l] == 'R') s[l] = 'L';
        else s[l] = 'R';
        update(0, 1, n + 1);
        if(can[0]) puts("YES");
        else puts("NO");
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int t; scanf("%d", &t);
    while(t--) solve();
	return 0;
}
