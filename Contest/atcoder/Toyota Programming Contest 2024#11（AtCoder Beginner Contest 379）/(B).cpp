#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

char s[102];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int n, k; scanf("%d %d %s", &n, &k, s);
    
    int ans = 0;
    for(int i = 0, j = 0; i < n; i = j) {
        for(; j < n && s[i] == s[j]; j++);
        if(s[i] == 'O') ans += (j - i) / k;
    }
    cout<<ans<<endl;
	return 0;
}
