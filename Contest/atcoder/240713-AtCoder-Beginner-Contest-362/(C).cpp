#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int L[NN], R[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	
	INT st = 0, ed = 0;
	for(int i = n; i--; ) {
		scanf("%d %d", L + i, R + i);
		st += L[i], ed += R[i];
	}
	
	if(st <= 0 && 0 <= ed) {
		puts("Yes");
		INT x = -st;
		
		for(int i = n; i--; ) {
			INT add = min(x, (INT)R[i] - L[i]);
			L[i] += add, x -= add;
			printf("%d ", L[i]);
		}
	}
	else puts("No");
	return 0;
}
