#include<bits/stdc++.h>

using namespace std;

int a[404040];

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, x, y; scanf("%d %d %d", &n, &x, &y);
		int c = __gcd(x, y);
		
		for(int i = 0; i < n; i++) {
			scanf("%d", a + i);
			a[i] %= c;
		}
		sort(a, a + n);
		for(int i = n; i--; ) a[n + i] = a[i] + c;
		
		int ans = a[n - 1] - a[0];
		for(int i = 0; i < n; i++) ans = min(ans, a[i + n - 1] - a[i]);
		printf("%d\n", ans);
	}
}