#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, k; scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= k && a[i] < 4; i++) a[i] = 7 - a[i];
		int ans = 0;
		for(int i = 1; i <= n; i++) ans += a[i];
		cout<<ans<<endl;
	}
	return 0;
}
