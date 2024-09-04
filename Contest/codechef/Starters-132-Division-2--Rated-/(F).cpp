#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020, mod = 1e9 + 7;

int power(int a, int b) {
	int ans = 1;
	for(; b; b >>= 1, a = (INT)a * a % mod) {
		if(b & 1) ans = (INT)ans * a % mod;
	}
	return ans;
}

int num[NN], sub[NN];
int percent[NN];
pii p[NN];

int solve() {
	int n, nn = 0, all_num = 0; scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", num + i), all_num += num[i];
		sub[i] = 0;
		for(int j = num[i]; j--; ) {
			int x; scanf("%d", &x);
			p[nn++] = {x, i};
		}
	}
	sort(p, p + nn);
	
	int ori = power(all_num, mod - 2), common = 0, ans = 0;
	for(int i = 0, j = 0; i < nn; i = j) {
		for(; j < nn & p[i].x == p[j].x; j++) {
			all_num--, num[p[j].y]--;
		}
		
		for(int k = i; k < j; k++) {
			int id = p[k].y, val = p[k].x;
			percent[id] = ((INT)common - sub[id] + mod + ori) % mod;
			ans = (ans + (INT)percent[id] * val) % mod;
		}
		for(int k = i; k < j; k++) {
			int id = p[k].y, val = p[k].x;
			
			int extra_num = all_num - num[id];
			if(extra_num) {
				int add_value = (INT)percent[id] * power(extra_num, mod - 2) % mod;
				common = (common + add_value) % mod;
				sub[id] = (sub[id] + add_value) % mod;
			}
		}
	}
	return ans;
}
		
int main() {	
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) printf("%d\n", solve());
	return 0;
}
