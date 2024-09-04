#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

int a[NN], b[NN], c[NN << 1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, m; scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++) scanf("%d", a + i);
		for(int i = 0; i < m; i++) scanf("%d", b + i);
		
		if(n < 4 || m < 4 || n + m < 11) puts("-1");
		else {
			sort(a, a + n, [&](int u, int v) {
				return u > v;
			});
			sort(b, b + m, [&](int u, int v) {
				return u > v;
			});
			
			int nn = 0;
			INT sum = 0;
			for(int i = 4; i--; ) sum += a[i] + b[i];
			for(int i = 4; i < n; i++) c[nn++] = a[i];
			for(int i = 4; i < m; i++) c[nn++] = b[i];
			sort(c, c + nn, [&](int u, int v) {
				return u > v;
			});
			for(int i = 3; i--; ) sum += c[i];
			
			printf("%lld\n", sum);
		}
	}
	return 0;
}
