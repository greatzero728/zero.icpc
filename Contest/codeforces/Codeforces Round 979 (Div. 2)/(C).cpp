#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

char s[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d %s", &n, s + 1);
        
        if(s[1] == '1' || s[n] == '1') puts("YES");
        else {
            bool ok = 0;
            for(int i = 1; i < n; i++) if(s[i] == '1' && s[i + 1] == '1') {
                ok = 1; break;
            }
            if(ok) puts("YES");
            else puts("NO");
        }
    }
	return 0;
}
