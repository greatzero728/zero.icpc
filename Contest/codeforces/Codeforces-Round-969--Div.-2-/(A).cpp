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
		int L, R; scanf("%d %d", &L, &R);
		int n = (R + 1 >> 1) - (L >> 1);
		cout<<n/2<<endl;
	}
	return 0;
}
