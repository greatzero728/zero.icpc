#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int a[121];

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
		int mx = 0;
		for(int i = 1, j = 1; i <= n; i = j) {
			for(; j <= n && a[i] == a[j]; j++);
			mx = max(mx, j - i);
		}
		
		if(mx >= k) printf("%d\n", min(n, k - 1));
		else printf("%d\n", n);
	}
	return 0;
}
