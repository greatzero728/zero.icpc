#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int a[101010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, mn, mx; scanf("%d %d %d", &n, &mn, &mx);
		
		for(int i = 1; i <= n; i++) a[i] = i;
		reverse(a + 1, a + mn + 1);
		reverse(a + 1, a + n + 1);
		
		for(int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
	}
	return 0;
}
