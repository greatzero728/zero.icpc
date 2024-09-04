#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int x[NN], y[NN];
INT dpx[NN], dpy[NN];

INT calc(int *x, INT *dp, int n, int i) {
	INT ans = 0; int id;
	id = upper_bound(x + 1, x + n + 1, i) - x, ans += dp[n] - dp[id - 1] - (INT)(n - (id - 1)) * i;
	id = lower_bound(x + 1, x + n + 1, i) - x, ans += (INT)(id - 1) * i - dp[id - 1];
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int n, d; scanf("%d %d", &n, &d);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", x + i, y + i);
	}
	
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	
	for(int i = 1; i <= n; i++) {
		dpx[i] = dpx[i - 1] + x[i];
		dpy[i] = dpy[i - 1] + y[i];
	}
	
	INT ans = 0;
	for(int i = x[1] - d; i <= x[n] + d; i++) {
		INT sx = calc(x, dpx, n, i);
		
		if(sx <= d) {
			int rest = d - sx, st, ed;
			
			st = y[1] - rest, ed = y[n] + rest;
			while(ed - st > 4) {
				int a = (st + st + ed) / 3;
				int b = (st + ed + ed) / 3;
				if(calc(y, dpy, n, a) > calc(y, dpy, n, b)) st = a;
				else ed = b;
			}
			int mn = calc(y, dpy, n, ed), id = ed;
			for(int j = st; j < ed; j++) {
				int val = calc(y, dpy, n, j);
				if(val < mn) mn = val, id = j;
			}
			
			st = y[1] - rest, ed = id;
			if(st <= ed) {
				st--; int ED = ed;
				while(ed - st > 1) {
					int md = st + ed >> 1;
					if(calc(y, dpy, n, md) <= rest) ed = md;
					else st = md;
				}
				if(calc(y, dpy, n, ed) <= rest) ans += ED - ed + 1;
			}
			
			st = id + 1, ed = y[n] + rest;
			if(st <= ed) {
				ed++; int ST = st;
				while(ed - st > 1) {
					int md = st + ed >> 1;
					if(calc(y, dpy, n, md) <= rest) st = md;
					else ed = md;
				}
				if(calc(y, dpy, n, st) <= rest) ans += st - ST + 1;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
