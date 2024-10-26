#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 121;

int w[NN], h[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d %d", w + i, h + i);
        
        printf("%d\n", *max_element(w + 1, w + n + 1) + *max_element(h + 1, h + n + 1) << 1);
    }
	return 0;
}
