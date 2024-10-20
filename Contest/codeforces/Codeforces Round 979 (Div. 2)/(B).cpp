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
        int n; scanf("%d", &n);
        int n0 = n - 1, n1 = n - n0;
        while(n0--) putchar('0');
        while(n1--) putchar('1');
        puts("");
    }
	return 0;  
}
