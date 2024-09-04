#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 505050;

int a[NN], n, N[2];
char s[NN];
vector<int> vec[2];

bool can(int k) {
	N[0] = vec[0].size();
	N[1] = vec[1].size();
	if(k <= vec[0].size()) return true;
	N[1] = k - vec[0].size();
	if(N[1] > n / 2) return false;
	
	int free = n - N[1] * 2 - 1;
	if(N[0] <= free) return true;
	N[0] -= free;
	
	vector<int> a;	
	for(int i = 0; i < N[0]; i++) a.push_back(vec[0][N[0] - 1 - i]);	
	sort(a.begin(), a.end());
	
	if(a.empty()) return true;
	if(a[0] <= vec[1][0]) return false;
	for(int i = 1; i + 1 < a.size(); i++) {
		if(a[i] <= vec[1][i - 1] || a[i] <= vec[1][i]) return false;
	}
	if(k == n) return a.back() > vec[1].back();
	return a.size() < 2 || a.back() > vec[1][a.size() - 2] && a.back() > vec[1][a.size() - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		scanf("%s", s + 1);
		
		for(int i = 2; i--; ) vec[i].clear();
		for(int i = 1; i <= n; i++) vec[s[i] == '1'].push_back(a[i]);
		for(int i = 2; i--; ) sort(vec[i].begin(), vec[i].end());
		
		int st = 1, ed = n + 1;
		while(ed - st > 1) {
			int md = (st + ed) / 2;
			if(can(md)) st = md;
			else ed = md;
		}
		printf("%d\n", st);
	}
	return 0;
}
