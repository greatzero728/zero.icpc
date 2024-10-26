#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int n, m; scanf("%d %d", &n, &m);
    set<pii> s;
    while(m--) {
        int x, y; scanf("%d %d", &x, &y);
        s.insert({x, y});
        for(int k = 8; k--; ) {
            int X = x + dx[k], Y = y + dy[k];
            if(1 <= X && X <= n && 1 <= Y && Y <= n) {
                s.insert({X, Y});
            }
        }
    }
    cout<<(INT)n * n - s.size()<<endl;
	return 0;
}
