#include<bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 202020;

int a[NN];
int val[NN], num[NN];

int solve() {
    int n, k; scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    
    int nn = 0;
    for(int i = 1, j = 1; i <= n; i = j) {
        for(; j <= n && a[i] == a[j]; j++);
        val[nn] = a[i], num[nn++] = j - i;
    }
    int ans = 1;
    for(int i = 0, j = 0; i < nn; i = j) {
        deque<int> q;
        int s = 0;
        for(; j < nn; j++) {
            if(i < j && val[j] - val[j - 1] > 1) break;
            q.push_back(num[j]), s += num[j];
            if(q.size() > k) s -= q.front(), q.pop_front();
            ans = max(ans, s);
        }
    }
    return ans;
}

int main() {
    
    int t; scanf("%d", &t);
    while(t--) printf("%d\n", solve());
	return 0;
}