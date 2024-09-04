#include<bits/stdc++.h>

using namespace std;
using INT = long long;

INT calc(int L, int R) {
	if(L > R) return 0;
	return ((INT)L + R) * (R - L + 1) >> 1;
}

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, k; scanf("%d %d", &n, &k);
		
		int L = k, R = k + n - 1;
		
		int st = L - 1, ed = R;
		while(ed - st > 1) {
			int md = (INT)st + ed >> 1;
			if(calc(L, md) - calc(md + 1, R) > 0) ed = md;
			else st = md;
		}
		INT ans = abs(calc(L, ed) - calc(ed + 1, R));
		if(ed > L) ed--, ans = min(ans, abs(calc(L, ed) - calc(ed + 1, R)));
		if(ed > L) ed--, ans = min(ans, abs(calc(L, ed) - calc(ed + 1, R)));
		printf("%I64d\n", ans);
	}
	return 0;
}
