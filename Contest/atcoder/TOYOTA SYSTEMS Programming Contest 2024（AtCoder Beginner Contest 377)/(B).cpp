#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

char s[11][11];
int x[11], y[11];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    for(int i = 1; i <= 8; i++) {
        scanf("%s", s[i] + 1);
        for(int j = 1; j <= 8; j++) {
            if(s[i][j] == '#') x[i] = 1, y[j] = 1;
        }
    }
    int ans = 0;
    for(int i = 1; i <= 8; i++) if(!x[i]) {
        for(int j = 1; j <= 8; j++) if(!y[j]) {
            ans++;
        }
    }
    cout<<ans<<endl;
	return 0;
}
