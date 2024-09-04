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
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		int ans = 1;
		for(int i = 0; i <= 5; i++) {
			for(int j = 0; j <= 5 - i; j++) {
				int k = 5 - i - j;
				ans = max(ans, (a + i) * (b + j) * (c + k));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
