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
		int n, k; scanf("%d %d", &n, &k);
		for(int i = 1; i <= k; i++) scanf("%d", a + i);
		
		int mx = *max_element(a + 1, a + k + 1);
		int ans = n - mx;
		for(int i = 1; i <= k; i++) {
			if(a[i] == mx) mx++;
			else ans += a[i] - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
