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
    
    int q; scanf("%d", &q);
    
    INT t = 0;
    multiset<INT> s;
    while(q--) {
        int tp; scanf("%d", &tp);
        if(tp == 1) s.insert(t);
        else if(tp == 2) {
            int x; scanf("%d", &x);
            t -= x;
        }
        else {
            int h; scanf("%d", &h);
            int ans = 0;
            while(!s.empty()) {
                INT u = *--s.end();
                if(u >= t + h) ans++, s.erase(--s.end());
                else break;
            }
            printf("%d\n", ans);
        }
    }
	return 0;
}
