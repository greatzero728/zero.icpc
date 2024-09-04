#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

vector<pii> vec;

const int NN = 202020;

int f[NN];
pii p[NN];
int num[55][55], a[NN], b[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	srand(time(0));
	int n, k; scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		num[a][b]++;
	}
	
	int nn = 0;
	for(int i = 1; i <= 50; i++) {
		for(int j = 1; j <= 50; j++) {
			for(int c = min(num[i][j], k); c--; ) {
				a[++nn] = i, b[nn] = j;
			}
		}
	}
	n = nn;
	for(int i = 1; i <= n; i++) p[i] = {a[i], b[i]};
	random_shuffle(p + 1, p + n + 1);
	
	if(n <= 10) {
		for(int i = 1; i <= n; i++) f[i] = i;
		
		INT ans = 1;
		do {
			INT s = 1;
			for(int i = 1; i <= k; i++) {
				int id = f[i], A = p[id].x, B = p[id].y;
				s = s * A + B;
			}
			ans = max(ans, s);
		}
		while(next_permutation(f + 1, f + n + 1));
		printf("%lld\n", ans);
		return 0;
	}
	
	for(int i = 1; i <= n; i++) {
		vec.push_back(p[i]);
	}
	
	INT s = 1;
	while(k--) {
		sort(vec.begin(), vec.end(), [&](pii a, pii b) {
			INT A = a.x * s + a.y, B = b.x * s + b.y;
			if(A == B) return a.x > b.x;
			return A < B;
		});
		s = vec.back().x * s + vec.back().y;
		vec.pop_back();
	}	
	INT ans = s;
	
	for(int i = 1; i <= n; i++) f[i] = i;
	int step = 2e8 / n + 8000;
	do {
		INT s = 1;
		for(int i = 1; i <= k; i++) {
			int id = f[i], A = p[id].x, B = p[id].y;
			s = s * A + B;
		}
		ans = max(ans, s);
		if(!step--) break;
	}
	while(next_permutation(f + 1, f + n + 1));
	printf("%lld\n", ans);
	return 0;
}
