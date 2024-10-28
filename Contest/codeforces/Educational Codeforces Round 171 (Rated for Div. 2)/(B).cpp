#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 2020;
const INT inf = 1e18;

INT a[NN], b[NN];
map<INT, bool> mp;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%I64d", a + i);
        
        if(n == 1) puts("1");
        else if(n & 1) {
            INT mn = a[n] - a[1];
            
            mp.clear();
            for(int i = 1; i <= n; i++) mp[a[i]] = 1;
            
            for(int i = 1; i <= n; i++) {
                int nn = 0;
                for(int j = 1; j <= n; j++) if(i != j) {
                    b[++nn] = a[j];
                }
                bool ok = true;
                INT mx = 0;
                for(int j = 1; j <= nn; j += 2) {
                    mx = max(mx, b[j + 1] - b[j]);
                }
                if(ok) {
                    mn = min(mn, mx);
                }
            }
            cout<<mn<<endl;
        }
        else {
            INT mx = 0;
            for(int i = 1; i <= n; i += 2) mx = max(mx, a[i + 1] - a[i]);
            cout<<mx<<endl;
        }
    }
	return 0;
}
