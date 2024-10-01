#include<bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
    while(t--) {
        int n, k; scanf("%d %d", &n, &k);
        if(k == 1) printf("%d\n", n);
        else {
            int ans = 0;
            while(n) {
                ans += n % k;
                n /= k;
            }
            printf("%d\n", ans);
        }
    }
}
