#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int num[121];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		for(int i = 1; i <= 100; i++) num[i] = 0;
		int st, ed;
		
		for(int k = 2; k--; ) {
			scanf("%d %d", &st, &ed);
			for(int i = st; i <= ed; i++) num[i]++;
		}
		int ans = 0;
		for(int i = 1; i <= 100; i++) if(num[i] == 2) ans++;
		if(ans) {
			ans--;
			for(int i = 1; i < 100; i++) {
				if(num[i] == 1 && num[i + 1] == 2) ans++;
				if(num[i] == 2 && num[i + 1] == 1) ans++;
			}
		}
		else ans = 1;
		printf("%d\n", max(ans, 1));
	}
	return 0;
}
