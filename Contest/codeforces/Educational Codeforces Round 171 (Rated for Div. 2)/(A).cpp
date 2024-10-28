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
    
    int t; scanf("%d", &t);
    while(t--) {
        int x, y, k; scanf("%d %d %d", &x, &y, &k);
        int d = min(x, y);
        printf("%d %d %d %d\n", 0, 0, d, d);
        printf("%d %d %d %d\n", 0, d, d, 0);
    }
	return 0;
}
