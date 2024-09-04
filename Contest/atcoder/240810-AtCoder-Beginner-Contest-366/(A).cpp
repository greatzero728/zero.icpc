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
	
	int n, t, a; scanf("%d %d %d", &n, &t, &a);
	int k = n + 1 >> 1;
	if(t >= k || a >= k) puts("Yes");
	else puts("No");
	return 0;
}
