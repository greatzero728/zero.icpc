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
        int n, r; scanf("%d %d", &n, &r);
        int odd = 0, ans = 0;
        while(n--) {
            int x; scanf("%d", &x);
            if(x & 1) ans += x - 1, odd++;
            else ans += x;
        }
        if(odd <= r - ans / 2) ans += odd;
        else ans += r - ans / 2 - (odd - (r - ans / 2));
        printf("%d\n", ans);
    }
	return 0;
}
