#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010, inf = 0x3f3f3f3f;

int dp[121], tmp[121];

int calc(int a, int b, int k, vector<pii> vec) {
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for(pii p: vec) {
		int wei = p.x, cost = p.y;
		memset(tmp, 0, sizeof tmp);
		for(int i = 0; i <= k; i++) {
			if(i + wei < 121) tmp[i + wei] = max(tmp[i + wei], dp[i] + cost);
		}
		for(int i = 121; i--; ) dp[i] = tmp[i];
	}
	int ans = dp[k];
	
	return ans;
}

int a[NN], b[NN];
vector<pii> vec;
int wei[NN], cost[NN];

int solve() {
	int n, k; scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", a + i, b + i);
		wei[i] = a[i] + b[i] - 1;
		cost[i] = a[i] * b[i];
	}
	
	int ans = inf;
	for(int i = 1; i <= n; i++) {
		int W = wei[i], C = cost[i]; vec.clear();
		for(int j = 1; j <= n; j++) if(i != j) {
			vec.push_back(wei[i], cost[i]);
		}
		ans = min(ans, calc(a[i], b[i], k, vec));
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) printf("%d\n", solve());
	return 0;
}
