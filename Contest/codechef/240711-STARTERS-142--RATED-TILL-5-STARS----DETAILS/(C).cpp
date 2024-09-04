#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, m; scanf("%d %d", &n, &m);
		INT ans = (INT)n * m + 2;
		if(min(n, m) == 2) {
			INT N = n * m;
			ans += (N - 2) / 4 * 2;
		}
		else ans += 2;
		printf("%lld\n", ans);
	}
}
