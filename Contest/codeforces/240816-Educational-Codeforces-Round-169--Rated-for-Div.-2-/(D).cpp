#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020, inf = 0x3f3f3f3f;

int dp[6][NN];

int tp(string s) {
	if(s == "BG") return 0;
	if(s == "BR") return 1;
	if(s == "BY") return 2;
	if(s == "GR") return 3;
	if(s == "GY") return 4;
	return 5;
}

string s[NN];

bool same(string a, string b) {
	map<char, int> mp;
	for(char c : a) mp[c]++;
	for(char c : b) mp[c]++;
	for(auto p : mp) if(p.y == 2) return 1;
	return 0;
}
vector<int> pos[6];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, q; scanf("%d %d", &n, &q);
		for(int i = 6; i--; ) pos[i].clear();
		for(int i = 1; i <= n; i++) {
			for(int k = 6; k--; ) dp[k][i] = dp[k][i - 1];
			cin>>s[i], dp[tp(s[i])][i]++;
			pos[tp(s[i])].push_back(i);
		}
		
		while(q--) {
			int L, R; scanf("%d %d", &L, &R);
			if(L > R) swap(L, R);
			if(same(s[L], s[R])) printf("%d\n", R - L);
			else {
				vector<int> vec;
				for(int i = 6; i--; ) if(i != tp(s[L]) && i != tp(s[R])) {
					vec.push_back(i);
				}
				int ans = inf;
				for(int k : vec) {
					if(dp[k][R] - dp[k][L - 1]) {ans = R - L; break;}
					
					int id = upper_bound(pos[k].begin(), pos[k].end(), R) - pos[k].begin();
					if(id < pos[k].size()) ans = min(ans, R - L + 2 * (pos[k][id] - R));
					
					id = lower_bound(pos[k].begin(), pos[k].end(), L) - pos[k].begin();
					if(id) id--, ans = min(ans, R - L + 2 * (L - pos[k][id]));
				}
				if(ans < inf) printf("%d\n", ans);
				else puts("-1");
			}
		}
	}
	return 0;
}
