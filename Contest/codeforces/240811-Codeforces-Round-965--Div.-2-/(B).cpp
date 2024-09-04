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
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		printf("%d ", a[n]);
		for(int i = 1; i < n; i++) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}
