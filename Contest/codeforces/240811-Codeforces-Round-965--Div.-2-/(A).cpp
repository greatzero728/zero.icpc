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
		int x, y, k; scanf("%d %d %d", &x, &y, &k);
		int s = k / 2;
		for(int i = 1; i <= s; i++) printf("%d %d\n", x - i, y - i);
		for(int i = 1; i <= s; i++) printf("%d %d\n", x + i, y + i);
		if(k & 1) printf("%d %d\n", x, y);
	}
	return 0;
}
