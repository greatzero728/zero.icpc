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
		int n, x, y; scanf("%d %d %d", &n, &x, &y);
		int ans = 0;
		while(n--) {
			int t; scanf("%d", &t);
			ans += min(t * x, y);
		}
		cout<<ans<<endl;
	}
	return 0;
}
