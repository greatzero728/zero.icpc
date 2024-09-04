#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using pip = pair<int, pii>;

const int NN = 88, mod = 998244353;

int a[NN], ans[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	map<pip, int> dp;
	for(int i = 1; i <= n; i++) {
		dp[{i, {0, 1}}] = 1;
		for(int j = 1; j < i; j++) {
			int d = a[i] - a[j];
			for(int len = 2; len <= j + 1; len++) {
				if(len == 2) dp[{i, {d, len}}] = (dp[{i, {d, len}}] + dp[{j, {0, 1}}]) % mod;
				else dp[{i, {d, len}}] = (dp[{i, {d, len}}] + dp[{j, {d, len - 1}}]) % mod;
			}
		}
	}
	
	for(auto p : dp) {
		ans[p.x.y.y] = (ans[p.x.y.y] + p.y) % mod;
	}
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
}