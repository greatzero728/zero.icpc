#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

set<int> s;
vector<int> vec;

int solve() {
	int n, x; scanf("%d %d", &n, &x);
	int num = 0, ans = 0;
	
	s.clear(), s.insert(1);
	for(int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		if(a == 1 || x % a);
		else {
			vec.clear();
			for(int t : s) if(x % (t * a) == 0) {
				vec.push_back(t * a);
			}
			for(int t : vec) s.insert(t);
			if(s.find(x) != s.end()) {
				ans++, num = 0;
				s.clear(), s.insert(1), s.insert(a);
			}
		}
		num++;
	}
	
	if(num) ans++;
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
