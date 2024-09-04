#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

vector<INT> dp[NN], x[NN];
int a[NN];

int n, m, k;
INT calc_weight(int x, int y) {
	int xmn = max(x, k), xmx = min(n, x + k - 1);
	int ymn = max(y, k), ymx = min(m, y + k - 1);
	return (INT)(xmx - xmn + 1) * (ymx - ymn + 1);
}

INT solve() {
	scanf("%d %d %d", &n, &m, &k);
	int w; scanf("%d", &w);
	for(int i = w; i--; ) scanf("%d", a + i);
	
	vector<pii> vec;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			vec.push_back({i, j});
		}
	}
	sort(vec.begin(), vec.end(), [&](pii a, pii b) {
		return calc_weight(a.x, a.y) > calc_weight(b.x, b.y);
	});
	sort(a, a + w, [&](int u, int v) {return u > v;});
	
	for(int i = 0; i <= n; i++) dp[i] = x[i] = vector<INT>(m + 1, 0);
	
	int nn = 0;
	for(pii p : vec) {
		int i = p.x, j = p.y;
		x[i][j] = a[nn];
		if(++nn == w) break;
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + x[i][j];
		}
	}
	
	INT ans = 0;
	for(int i = k; i <= n; i++) {
		for(int j = k; j <= m; j++) {
			ans += dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) printf("%lld\n", solve());
	return 0;
}
