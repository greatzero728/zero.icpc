#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

vector<int> ans;

int n, k;

bitset<1000010> s;

bool insert(int i) {
	if(k - i >= 0 && s[k - i]) return false;
	s = s | (s << i);
	ans.push_back(i);
	return true;
}

void solve() {
	scanf("%d %d", &n, &k);
	s.reset(), s.set(0);
	ans.clear();
	for(int i = 1; i <= n && ans.size() < 25; i++) {
		if(i != k && s[i] == 0) {
			for(int j = i; !insert(j); j--);
		}
	}
	printf("%d\n", ans.size());
	for(int x : ans) printf("%d ", x);
	puts("");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}
