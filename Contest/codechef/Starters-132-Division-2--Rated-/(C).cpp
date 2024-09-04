#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

bool flag[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = n; i--; ) {
			int x; scanf("%d", &x);
			flag[i] = x & 1;
		}
		
		int mx = -1, L, R;
		for(int i = 0, j = 0; i < n; i = j) {
			for(; j < n && flag[i] == flag[j]; j++);
			if(flag[i] && j - i > mx) mx = j - i, L = i, R = j;
		}
		if(~mx) flag[L + R >> 1] = 0;
		
		int last = -1;
		INT ans = (INT)n * (n + 1) >> 1;
		for(int i = 0; i < n; i++) {
			if(flag[i] == 0) last = i;
			ans -= i - last;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
