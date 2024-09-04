#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define x first
#define y second

const int NN = 2e5 + 7;

vector<long long> dp[NN], x[NN];
int a[NN];

int n, m, k;
long long calc_weight(int x, int y) {
	int stR = max(x, k), edR = min(n, x + k - 1);
	int stU = max(y, k), edU = min(m, y + k - 1);
	return (long long)(edR - stR + 1) * (edU - stU + 1);
}

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int w; cin>>n>>m>>k>>w;
		vector<pii> vec;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				vec.push_back({i, j});
			}
			dp[i] = x[i] = vector<long long>(m + 1, 0);
		}
		dp[0] = x[0] = vector<long long>(m + 1, 0);
		
		for(int i = w; i--; ) cin>>a[i];
		sort(a, a + w), reverse(a, a + w);
		
		sort(vec.begin(), vec.end(), [&](pii a, pii b) {
			return calc_weight(a.first, a.second) > calc_weight(b.first, b.second);
		});
		
		int nn = 0;
		for(pii p : vec) {
			x[p.first][p.second] = a[nn];
			if(++nn == w) break;
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + x[i][j];
			}
		}
		
		long long ans = 0;
		for(int i = k; i <= n; i++) {
			for(int j = k; j <= m; j++) {
				ans += (dp[i][j] - dp[i - k][j]);
				ans -= (dp[i][j - k] - dp[i - k][j - k]);
			}
		}
		cout<<ans<<endl;
	}
}
