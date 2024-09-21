#include<bits/stdc++.h>

using namespace std;

const int NN = 101010;

int add[NN], del[NN];

void solve() {
    int n, d, k; scanf("%d %d %d", &n, &d, &k);
    for(int i = 1; i <= n; i++) {
        add[i] = del[i] = 0;
    }
    while(k--) {
        int l, r; scanf("%d %d", &l, &r);
        add[l]++, del[r]++;
    }
    int st = 1, ed = st + d - 1;
    
    int num = 0;
    for(int i = st; i <= ed; i++) num += add[i];
    int mn = num, lmn = st;
    int mx = num, lmx = st;
    for(; ed <= n; st++, ed++) {
        if(num < mn) mn = num, lmn = st;
        if(num > mx) mx = num, lmx = st;
        num += add[ed + 1];
        num -= del[st];
    }
    printf("%d %d\n", lmx, lmn);
}

int main() {
    int t; scanf("%d", &t);
    while(t--) solve();
	return 0;
}
