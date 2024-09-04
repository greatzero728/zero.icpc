#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 121;

int a[NN][NN][NN], dp[NN][NN][NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) scanf("%d", a[i][j] + k);
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k] + a[i][j][k];
			}
		}
	}
	
	int q; scanf("%d", &q);
	while(q--) {
		int ist, ied; scanf("%d %d", &ist, &ied);
		int jst, jed; scanf("%d %d", &jst, &jed);
		int kst, ked; scanf("%d %d", &kst, &ked);
		int ans = 0;
		for(int k = kst; k <= ked; k++) {
			ans += dp[ied][jed][k] - dp[ist - 1][jed][k] - dp[ied][jst - 1][k] + dp[ist - 1][jst - 1][k];
		}
		printf("%d\n", ans);
	}
		
	return 0;
}
