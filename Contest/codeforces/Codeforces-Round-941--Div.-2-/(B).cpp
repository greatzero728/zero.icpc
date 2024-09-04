#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 505;

char s[NN][NN];

bool same(int n, int m) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i][j] != s[1][1]) return false;
		}
	}
	return true;
}

bool solve() {
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	if(s[1][1] == s[n][m]) return true;
	if(s[n][1] == s[1][m]) return true;
	if(same(n, m)) return true;
	if(n > 1 && s[1][1] == s[1][m]) {
		for(int i = 2; i < m; i++) {
			if(s[1][1] != s[1][i]) return true;
			if(s[n][1] != s[n][i]) return true;
		}
		return false;
	}
	if(m > 1 && s[1][1] == s[n][1]) {
		for(int i = 2; i < n; i++) {
			if(s[1][1] != s[i][1]) return true;
			if(s[1][m] != s[i][m]) return true;
		}
		return false;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		if(solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}
