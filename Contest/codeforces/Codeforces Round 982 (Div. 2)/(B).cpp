#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 2020, inf = 1e9 + 1;

int a[NN];

int solve() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    
    int ans = n;
    for(int i = 1; i <= n; i++) {
        int num = i - 1;
        for(int j = i + 1; j <= n; j++) if(a[j] > a[i]) num++;
        ans = min(ans, num);
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int t; scanf("%d", &t);
    while(t--) printf("%d\n", solve());
	return 0;
}
