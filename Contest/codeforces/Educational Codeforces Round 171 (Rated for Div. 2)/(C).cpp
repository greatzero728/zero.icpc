#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 404040;

bool flag[NN];
char a[NN];
set<int> s[2];
set<int> :: iterator it;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d %s", &n, a + 1);
        
        for(int i = 1; i <= n; i++) {
            flag[i] = 0;
        }
        s[0].clear(), s[1].clear();
        for(int i = 1; i <= n; i++) s[a[i] == '1'].insert(i);
        
        INT ans = 0;
        for(int i = n; i >= 1; i--) if(a[i] == '1' && !flag[i]) {
            it = s[0].lower_bound(i);
            if(it != s[0].begin()) {
                ans += *--it;
//                cerr<<i<<' '<<*it<<endl;
                flag[*it] = 1, s[0].erase(it);
                flag[i] = 1, s[1].erase(i);
            }
            else {
                it = s[1].begin();
                if(*it < i) {
                    ans += *it;
                    flag[*it] = 1, s[1].erase(it);
                    flag[i] = 1, s[1].erase(i);
                }
            }
//            for(int j = 1; j <= n; j++) cout<<flag[j]<<' '; puts("");
        }
        for(int i = 1; i <= n; i++) if(!flag[i]) ans += i;
        printf("%I64d\n", ans);
    }
	return 0;
}
