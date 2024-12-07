#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

char s[NN];
INT a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int n; scanf("%d", &n);
    scanf("%s", s + 1);
    
    for(int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (INT)i * (s[i] - '0');
    }
    reverse(a + 1, a + n + 1);
    
    vector<int> ans;
    int ed = 1;
    while(a[ed]) {
        ans.push_back(a[ed] % 10);
        a[ed + 1] += a[ed] / 10;
        ed++;
    }
    for(int i = ans.size(); i--; ) printf("%d", ans[i]);
	return 0;
}
