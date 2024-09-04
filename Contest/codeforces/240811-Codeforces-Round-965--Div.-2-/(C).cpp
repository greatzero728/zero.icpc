#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020, inf = 2e9;

pii p[NN];
int n, k;

int calc_pos_of_median(int x) {
	int id = n / 2;
	if(x > id) return id;
	return id + 1;
}

int a0[NN], n0;
int a1[NN], n1;
INT dp[NN];

bool can(int i, INT mx) {
	int num = n / 2 - 1;
	
	int current_num = lower_bound(a0 + 1, a0 + n0 + 1, mx) - a0 - 1;
	if(current_num > num) return false;
	num -= current_num;
	
	int id = lower_bound(a1 + 1, a1 + n1 + 1, mx) - a1;
	if(id - 1 <= num) return true;
	return (INT)(id - 1 - num) * mx - (dp[id - 1] - dp[num]) <= k;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++) scanf("%d", &p[i].x);
		for(int i = 1; i <= n; i++) scanf("%d", &p[i].y);
		
		sort(p + 1, p + n + 1, [&](pii a, pii b) {
			return a.x < b.x;
		});
		
		n0 = n1 = 0;
		for(int i = 1; i <= n; i++) {
			if(p[i].y) a1[++n1] = p[i].x;
			else a0[++n0] = p[i].x;
		}
		for(int i = 1; i <= n1; i++) dp[i] = dp[i - 1] + a1[i];
		
		INT ans = 0;
		for(int i = 1; i <= n; i++) {
			int pos = calc_pos_of_median(i);
			if(p[i].y) ans = max(ans, (INT)p[i].x + p[pos].x + k);
			else {
				INT st = p[1].x, ed = inf;
				while(ed - st > 1) {
					INT md = st + ed >> 1;
					if(can(i, md)) st = md;
					else ed = md;
				}
				ans = max(ans, p[i].x + st);
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
