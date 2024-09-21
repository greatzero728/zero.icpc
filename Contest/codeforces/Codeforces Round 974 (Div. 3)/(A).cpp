#include<bits/stdc++.h>

using namespace std;

int a[121];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n, k; scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        
        int s = 0, ans = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] >= k) s += a[i];
            else if(!a[i]) {
                if(s) s--, ans++;
            }
        }
        printf("%d\n", ans);
    }
}