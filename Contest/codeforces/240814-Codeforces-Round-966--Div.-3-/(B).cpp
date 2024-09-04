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
		int n; scanf("%d", &n);
		int L, R, ok = 1; scanf("%d", &L), R = L;
		while(--n) {
			int x; scanf("%d", &x);
			if(x == L - 1) L--;
			else if(x == R + 1) R++;
			else ok = 0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
