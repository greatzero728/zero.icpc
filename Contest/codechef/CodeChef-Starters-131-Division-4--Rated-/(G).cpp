#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

map<int, int> mp;

const int NN = 10000010;

int vst[NN], runs;
int p_vst[NN], p_runs;
int num[NN], n_vst[NN], n_runs;
int ans;

void add_num(int i) {
	if(p_vst[i] != p_runs) {
		p_vst[i] = p_runs;
		if(n_vst[i] != n_runs) num[i] = 0, n_vst[i] = n_runs;
		if(++num[i] == 2) ans = max(ans, i);
	}
	p_vst[i] = p_runs;
}

void update(int x) {
	vector<int> a;
	while(x) a.push_back(x % 10), x /= 10;
	sort(a.begin(), a.end());
	
	p_runs++, runs++;
	do {
		if(a[0] == 0) continue;
		
		int u = 0;
		for(int x : a) u = u * 10 + x;
		if(vst[u] == runs && u <= ans) continue;
		vst[u] = runs;
		
		for(int i = 2, ed = u; i * i <= ed; i++) if(u % i == 0) {
			if(i > ans) add_num(i);
			while(u % i == 0) u /= i;
		}
		if(u > ans) add_num(u);
	}
	while(next_permutation(a.begin(), a.end()));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int x, y; scanf("%d %d", &x, &y);
		
		ans = 1, n_runs++;
		update(x), update(y);
		
		printf("%d\n", ans);
	}
	return 0;
}
