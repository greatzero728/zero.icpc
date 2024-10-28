#include<bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 303030;

int a[NN], n;
INT dp[NN], DP[NN];
INT sum[NN];
INT len[NN];
INT ddp[NN];

INT calc(INT N) {
    if(!N) return 0;
    int id = lower_bound(len + 1, len + n + 1, N) - len;
    INT ans = sum[id - 1];
    int L = id, R = L - 1 + N - len[id - 1];
    return ans + (ddp[R] - ddp[L - 1]) - dp[L - 1] * (R - L + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        dp[i] = dp[i - 1] + a[i];
        ddp[i] = ddp[i - 1] + dp[i];
    }
    for(int i = n; i >= 1; i--) {
        DP[i] = DP[i + 1] + (INT)a[i] * (n + 1 - i);
    }
    for(int i = 1; i <= n; i++) {
        len[i] = len[i - 1] + n - i + 1;
        INT s = DP[i];
        sum[i] = sum[i - 1] + s;
    }
    
    int q; scanf("%d", &q);
    while(q--) {
        INT l, r; scanf("%I64d %I64d", &l, &r);
        printf("%I64d\n", calc(r) - calc(l - 1));
    }
	return 0;
}
