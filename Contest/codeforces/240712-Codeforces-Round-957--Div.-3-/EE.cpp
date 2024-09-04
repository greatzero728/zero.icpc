#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int calc_len(int n) {
	if(n <= 9) return 1;
	if(n <= 99) return 2;
	if(n <= 999) return 3;
	if(n <= 9999) return 4;
	if(n <= 99999) return 5;
	return 6;
}

bool can(int n, int a, int b) {
	int val = n * a - b;
	int len = calc_len(val);
	int n_len = calc_len(n);
	int sz = n_len * a - b;
	if(sz != len) return false;
	
	vector<int> B;
	while(val) B.push_back(val % 10), val /= 10;
	reverse(B.begin(), B.end());
	
	vector<int> A;
	while(n) A.push_back(n % 10), n /= 10;
	reverse(A.begin(), A.end());
	
	n = A.size();
	for(int i = A.size(); i < B.size(); i++) {
		if(A[i % n] != B[i]) return false;
	}
	for(int i = A.size(); i--; ) if(A[i] != B[i]) return false;
	return true;
}

void solve(int n) {
	vector<pii> ans;
	for(int a = 1; a <= 10000; a++) {
		int st = 1, ed = min(10000, a * n);
		int len = calc_len(n) * a;
		st = max(st, len - 10);
		ed = min(ed, len + 10);
		for(int b = st; b <= ed; b++) {
			if(can(n, a, b)) ans.push_back({a, b});
		}
	}
	printf("%d\n", ans.size());
	for(pii p : ans) printf("%d %d\n", p.x, p.y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		solve(n);
	}
	return 0;
}
