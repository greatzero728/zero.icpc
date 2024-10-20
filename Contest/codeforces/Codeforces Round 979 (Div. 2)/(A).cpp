#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        printf("%d\n", (*max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1)) * (n - 1));
    }
	return 0;
}
