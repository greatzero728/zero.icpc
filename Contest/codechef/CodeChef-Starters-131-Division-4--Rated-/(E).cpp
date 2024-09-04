#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int mod = 1e9 + 7, NN = 202020;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		
		int ans;
		if(a[1] == 1) {
			if(a[n] == 1) ans = n;
			else {
				for(int i = 1; i <= n; i++) if(a[i] > 1) {
					if(i == 2) {
						ans = 1 + a[i];
						for(int j = i + 1; j <= n; j++) ans = (INT)ans * a[j] % mod;
					}
					else {
						ans = i - 1;
						for(int j = i; j <= n; j++) ans = (INT)ans * a[j] % mod;
					}
					break;
				}
			}
		}
		else {
			ans = a[1];
			for(int i = 2; i <= n; i++) ans = (INT)ans * a[i] % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
