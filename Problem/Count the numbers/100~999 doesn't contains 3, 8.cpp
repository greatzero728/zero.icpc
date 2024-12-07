#include <bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

bool can(int x) {
    while(x) {
        int c = x % 10;
        if(c == 3) return 0;
        if(c == 8) return 0;
        x /= 10;
    }
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

    int ans = 0;
    for(int i = 100; i <= 999; i++) {
        if(can(i)) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
