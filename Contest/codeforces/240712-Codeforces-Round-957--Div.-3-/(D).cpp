#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

char s[NN];
int dp[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		scanf("%s", s + 1);
		s[0] = s[n + 1] = 'L';
		
		int inf = k + 1;
		for(int i = 1; i <= n + 1; i++) dp[i] = inf;
		
		for(int i = 0; i <= n; i++) if(dp[i] < inf) {
			int ed;
			if(s[i] == 'L') ed = m;
			else ed = 1;
			for(int j = 1; j <= ed; j++) if(i + j <= n + 1 && s[i + j] != 'C') {
				dp[i + j] = min(dp[i + j], dp[i] + (s[i + j] == 'W'));
			}
		}
		
		if(dp[n + 1] < inf) puts("YES");
		else puts("NO");
	}
	return 0;
}
