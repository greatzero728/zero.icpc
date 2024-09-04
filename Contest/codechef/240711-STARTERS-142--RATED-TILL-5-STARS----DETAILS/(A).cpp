#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;
int a[NN];

int calc(int x) {
	while(x % 2 == 0) x /= 2;
	return x;
}

int solve() {
	int n; scanf("%d", &n);
	int mx = 0;
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	
	int s = 0;
	for(int i = 1; i <= n; i++) {
		s |= a[i];
		int k = s + 1;
		if(calc(k) == 1) mx = i;
	}
	return n - mx;
}	

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) printf("%d\n", solve());
	return 0;
}
