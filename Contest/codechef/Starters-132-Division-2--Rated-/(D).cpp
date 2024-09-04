#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

int num[3][NN], N[3];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			for(int j = 3; j--; ) num[j][i] = num[j][i - 1];
			if(1 <= x && x <= 2) num[x][i]++;
			else num[0][i]++;
		}
		int q; scanf("%d", &q);
		while(q--) {
			int L, R, k; scanf("%d %d %d", &L, &R, &k);
			for(int j = 3; j--; ) N[j] = num[j][R] - num[j][L - 1];
			int num_0_12 = min(k, N[0]), cnt = min(abs(N[1] - N[2]), num_0_12);
			int num_12 = k - num_0_12;
			
			num_0_12 -= cnt;
			if(N[1] < N[2]) N[1] += cnt;
			else N[2] += cnt;
			
			N[1] += num_0_12 / 2;
			N[2] += num_0_12 - num_0_12 / 2;
			
			INT ans = (INT)N[1] * N[2];
			cnt = min(abs(N[1] - N[2]) / 2, num_12);
			for(int i = cnt; i < cnt + 3 && i <= num_12; i++) {
				if(N[1] < N[2]) ans = max(ans, (INT)(N[1] + i) * (N[2] - i));
				else ans = max(ans, (INT)(N[2] + i) * (N[1] - i));
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
