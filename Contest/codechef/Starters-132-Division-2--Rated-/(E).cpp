#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

int num[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", num + i);
		num[n] = 0;
		
		int ans = 0;
		for(int i = 0; i <= n; i++) {
			if(!~ans) {printf("-1 "); continue;}
			printf("%d ", ans + num[i]);
			if(!num[i]) {
				for(int x = i, dep = 0; ; x >>= 1, dep++) {
					if(num[x] > 1) {
						num[x]--, num[i] = 1, ans += dep;
						break;
					}
					if(!x) break;
				}
			}
			if(!num[i]) ans = -1;
		}
		puts("");
	}
	return 0;
}
