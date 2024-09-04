#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int a[NN];
INT dp[NN];
char s[NN];

INT solve() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	scanf("%s", s + 1);
	
	vector<int> L, R;
	for(int i = n; i; i--) {
		if(s[i] == 'L') L.push_back(i);
		else R.push_back(i);
	}
	reverse(R.begin(), R.end());
	
	for(int i = 1; i <= n; i++) dp[i] = dp[i - 1] + a[i];
	
	INT ans = 0;
	while(!L.empty() and !R.empty()) {
		int st = L.back(), ed = R.back();
		L.pop_back(), R.pop_back();
		if(st <= ed) ans += dp[ed] - dp[st - 1];
		else break;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) printf("%I64d\n", solve());
	return 0;
}
