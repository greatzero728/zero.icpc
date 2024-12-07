#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int a, b, c; scanf("%1d%1d%1d", &a, &b, &c);
    printf("%d%d%d %d%d%d\n", b, c, a, c, a, b);
	return 0;
}
