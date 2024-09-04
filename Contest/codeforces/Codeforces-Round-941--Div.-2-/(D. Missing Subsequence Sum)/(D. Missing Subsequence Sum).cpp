#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

void solve() {
	int n, k, c = 0; scanf("%d %d", &n, &k);
	while((1 << c) <= k) c++; c--;
	puts("22");
	printf("%d %d ", k - (1 << c), k + 1);
	for(int i = 20; i--; ) if(i != c) printf("%d ", 1 << i);
	if(k < (1 << c + 1) - 1) {
		printf("%d\n", (1 << c + 1) - 1);
	}
	else {
		printf("%d\n", (1 << c + 1) + k);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}