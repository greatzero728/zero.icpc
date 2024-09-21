#include<bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n, k; scanf("%d %d", &n, &k);
        int st = n - k + 1, ed = n;
        int x = (ed + 1) / 2 - st / 2;
        if(x & 1) puts("NO");
        else puts("YES");
    }
}