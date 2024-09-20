#include<bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        int x, y; scanf("%d %d", &x, &y);
        int c = min(x, y);
        printf("%d\n", (n + c - 1) / c);
    }
}
