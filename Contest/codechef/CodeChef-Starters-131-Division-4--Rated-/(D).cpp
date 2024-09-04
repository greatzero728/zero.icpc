#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int a[NN << 1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, k; scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i), a[i] %= k;
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i < n; i++) a[n + i] = a[i] + k;
		
		int ans = k;
		for(int i = n; i < 2 * n; i++) ans = min(a[i] - a[i - n + 1], ans);
		printf("%d\n", ans);
	}
	return 0;
}
