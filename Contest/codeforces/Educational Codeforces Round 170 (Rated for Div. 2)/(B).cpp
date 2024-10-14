#include<bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 101010, mod = 1e9 + 7;

int power(int a, int b) {
    int ans = 1;
    for(; b; b >>= 1, a = (INT)a * a % mod) {
        if(b & 1) ans = (INT)ans * a % mod;
    }
    return ans;
}

int n[NN], k[NN];

int main() {
    
    int t; scanf("%d", &t);
    for(int i = 1; i <= t; i++) scanf("%d", n + i);
    for(int i = 1; i <= t; i++) scanf("%d", k + i);
    
    for(int i = 1; i <= t; i++) {
        if(k[i] > n[i]) puts("0");
        else if(n[i] == k[i]) puts("1");
        else printf("%d\n", power(2, k[i]));
    }
	return 0;
}
