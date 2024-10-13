#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 505050;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int t; scanf("%d", &t);
    while(t--) {
        int n, x; scanf("%d %d", &n ,&x);
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        
        INT sum = 0;
        int mx = a[1];
        for(int i= 1; i <= n; i++) sum += a[i], mx = max(a[i], mx);
        printf("%I64d\n", max((INT)mx, (sum + x - 1) / x));
    }
	return 0;
}
