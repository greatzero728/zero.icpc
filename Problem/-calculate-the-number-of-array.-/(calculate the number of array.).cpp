#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 25252, MM = 404, mod = 1e9 + 7;

int power(int a, int b) {
	int ans = 1;
	for(; b; b >>= 1, a = (INT)a * a % mod) if(b & 1) {
		ans = (INT)ans * a % mod;
	}
	return ans;
}

int dp[NN][MM];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	if(m == 1) return puts("1"), 0;
	
	for(int i = 1; i <= n; i++) {
		int ed = min(m - 1, i);
		for(int j = 2; j < ed; j++) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
		
		for(int j = 1; j <= ed; j++) {
			if(j == 1) {
				if(i == 1) dp[i][j] = m;
				else dp[i][j] = power(m, i - 1);
			}
			if(i == n) continue;
			if(j + 1 < m) {
				int add = (INT)dp[i][j] * (m - j) % mod;
				dp[i + 1][j] = (dp[i + 1][j] + add) % mod;
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] - add + mod) % mod;
			}
			
			int add = (INT)dp[i][j] * power(j, mod - 2) % mod;
			dp[i + 1][2] = (dp[i + 1][2] + add) % mod;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] - add + mod) % mod;
		}
	}
	
	int ans = 0;
	for(int i = 1; i < m; i++) ans = (ans + dp[n][i]) % mod;
	printf("%d\n", (power(m, n) - ans + mod) % mod);
	return 0;
}