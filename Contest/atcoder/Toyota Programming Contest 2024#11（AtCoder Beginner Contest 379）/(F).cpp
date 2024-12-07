#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using pii = pair<int, int>;

const int NN = 202020, MM = NN << 1;

int h[NN];
int ls[MM], rs[MM], mx[MM];
int ll, rr, nn;

#define mid (L + R >> 1)

int build(int L, int R) {
    int u = nn++;
    if(R - L == 1) mx[u] = h[L];
    else {
        ls[u] = build(L, mid);
        rs[u] = build(mid, R);
        mx[u] = max(mx[ls[u]], mx[rs[u]]);
    }
    return u;
}

int calc_max(int u, int L, int R) {
    if(ll <= L && R <= rr) return mx[u];
    else {
        int mx = 0;
        if(ll < mid) mx = max(mx, calc_max(ls[u], L, mid));
        if(mid < rr) mx = max(mx, calc_max(rs[u], mid, R));
        return mx;
    }
}

int bi[NN], n;

int calc(int u) {
    int ans = 0;
    for(; u <= n; u += u & -u) ans += bi[u];
    return ans;
}
void update(int u, int x) {
    for(; u; u ^= u & -u) bi[u] += x;
}

vector<pii> query[NN];
int ans[NN];
multiset<int> s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int q; scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d", h + i);
    build(1, n + 1);
    
    for(int i = q; i--; ) {
        int l, r; scanf("%d %d", &l, &r);
        query[r].push_back({l, i});
    }
    
    for(int r = n; r; r--) {
        while(!s.empty()) {
            int H = *s.begin();
            if(h[r] > H) {
                s.erase(s.begin());
                update(H, -1);
            }
            else break;
        }
        int R = r;
        for(pii p : query[R]) {
            int L = p.x, id = p.y;
            ll = L + 1, rr = R + 1;
            int mx = calc_max(0, 1, n + 1);
            ans[id] = calc(mx);
        }
        
        s.insert(h[r]);
        update(h[r], 1);
    }
    
    for(int i = q; i--; ) {
        printf("%d\n", ans[i]);
    }
	return 0;
}
