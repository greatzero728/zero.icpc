#include<bits/stdc++.h>

using namespace std;

const int NN = 202020;

int dp[NN][30], rp[NN][30];
char s[NN];

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		scanf(" %s", s + 1);
		
		for(int i = 1; i <= n; i++) {
			for(int j = 26; j--; ) {
				dp[i][j] = 0;
				if(i >= 2) dp[i][j] = dp[i - 2][j];
			}
			dp[i][s[i] - 'a']++;
		}
		
		for(int i = 26; i--; ) rp[n + 1][i] = rp[n + 2][i] = 0;
		for(int i = n; i >= 1; i--) {
			for(int j = 26; j--; ) {
				rp[i][j] = rp[i + 2][j];
			}
			rp[i][s[i] - 'a']++;
		}
		
		int ans = 0;
		if(n & 1) {
			ans = n;
			for(int i = 1; i <= n; i++) {
				int s = 1;
				int mx = 0;
				for(int j = 26; j--; ) mx = max(mx, dp[i - 1][j] + rp[i + 2][j]);
				s += n / 2 - mx;
				
				mx = 0;
				for(int j = 26; j--; ) {
					int add = rp[i + 1][j];
					if(i >= 2) add += dp[i - 2][j];
					mx = max(mx, add);
				}
				s += n / 2 - mx;
				
				ans = min(ans, s);
			}
		}
		else {
			int mx = 0;
			for(int i = 26; i--; ) mx = max(mx, dp[n][i]);
			ans += n / 2 - mx;
			
			mx = 0;
			for(int i = 26; i--; ) mx = max(mx, dp[n - 1][i]);
			ans += n / 2 - mx;
		}
		printf("%d\n", ans);
	}
	return 0;
}
