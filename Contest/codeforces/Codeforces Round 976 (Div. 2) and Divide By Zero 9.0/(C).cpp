#include<bits/stdc++.h>

using namespace std;
using INT = long long;

INT solve() {
    INT B, C, D; scanf("%I64d %I64d %I64d", &B, &C, &D);
    INT A = B ^ D;
    if((A|B) - (A&C) == D) return A;
    A = C ^ D;
    if((A|B) - (A&C) == D) return A;
    return -1;
}

int main() {
	int t; scanf("%d", &t);
    while(t--) printf("%I64d\n", solve());
}