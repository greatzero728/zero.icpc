#include<bits/stdc++.h>

using namespace std;

const int NN = 101010;

int b[NN];

int main() {
    
    int t; scanf("%d", &t);
    while(t--) {
        int n, m, q; scanf("%d %d %d", &n, &m, &q);
        for(int i = 1; i <= m; i++) scanf("%d", b + i);
        sort(b + 1, b + m + 1);
        
        while(q--) {
            int x; scanf("%d", &x);
            int id = upper_bound(b + 1, b + m + 1, x) - b, ans;
            if(id == m + 1) ans = n - b[m];
            else {
                int R = b[id];
                if(id == 1) ans = R - 1;
                else {
                    int L = b[id - 1];
                    ans = R - L >> 1;
                }
            }
            printf("%d\n", ans);
        }
    }
}