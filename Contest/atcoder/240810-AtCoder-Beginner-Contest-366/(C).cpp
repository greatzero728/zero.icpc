#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int num[1010101];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t, ans = 0; scanf("%d", &t);
	while(t--) {
		int tp, x; scanf("%d", &tp);
		if(tp == 1) {
			scanf("%d", &x);
			if(!num[x]++) ans++;
		}
		else if(tp == 2) {
			scanf("%d", &x);
			if(!--num[x]) ans--;
		}
		else printf("%d\n", ans);
	}
	return 0;
}
