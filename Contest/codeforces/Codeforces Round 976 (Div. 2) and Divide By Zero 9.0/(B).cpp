#include<bits/stdc++.h>

using namespace std;
using INT = long long;

int a[101010];

INT calc(INT x) {
    INT y = sqrt(x) + 10;
    while(y * y > x) y--;
    return y;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        INT k; scanf("%I64d", &k);
        INT st = 1, ed = k + k;
        while(ed - st > 1) {
            INT md = st + ed >> 1;
            if(md - calc(md) >= k) ed = md;
            else st = md;
        }
        printf("%I64d\n", ed);
    }
}
