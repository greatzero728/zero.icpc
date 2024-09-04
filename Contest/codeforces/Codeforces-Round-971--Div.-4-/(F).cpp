#include<bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 404040;

int a[NN], n;
INT dp[NN];

INT calc(INT m) {
	int k = m / n;
	INT ans = k * dp[n];
	if(m % n) {
		k++;
		ans += dp[m % n + k - 1] - dp[k - 1];
	}
	return ans;
}

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int q; scanf("%d %d", &n, &q);
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			a[n + i] = a[i];
		}
		for(int i = 1; i <= 2 * n; i++) {
			dp[i] = dp[i - 1] + a[i];
		}
		
		while(q--) {
			INT L, R; scanf("%I64d %I64d", &L, &R);
			printf("%I64d\n", calc(R) - calc(L - 1));
		}
	}
	return 0;
}
