#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int a[202020];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, k; scanf("%d %d", &n, &k);
		
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + n + 1, [&](int u, int v) {
			return u > v;
		});
		
		a[n + 1] = a[n];
		
		INT ans = 0;
		if(n & 1) ans = a[n];
		
		for(int i = 1; i + 1 <= n; i += 2) {
			int add = a[i] - a[i + 1];
			int mn = min(add, k); add -= mn, k -= mn;
			ans += add;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
