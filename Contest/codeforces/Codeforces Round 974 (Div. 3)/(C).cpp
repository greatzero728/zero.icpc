#include<bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 202020;

int a[NN];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        if(n <= 2) {puts("-1"); continue;}
        
        sort(a + 1, a + n + 1);
        
        INT sum = 0;
        for(int i = 1; i <= n; i++) sum += a[i];
        
        int k = (n + 2) / 2;
        printf("%I64d\n", max(2LL * n * a[k] - sum + 1, 0LL));
    }
}
