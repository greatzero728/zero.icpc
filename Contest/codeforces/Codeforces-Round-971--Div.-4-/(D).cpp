#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using pii = pair<int, int>;

pii p[202020];

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		
		sort(p, p + n);
		
		INT ans = 0;
		for(int i = 0, j = 0; i < n; i = j) {
			for(; j < n && p[i].x == p[j].x; j++);
			if(j - i == 2) ans += n - 2;
		}
		
		map<pii, bool> mp;
		for(int i = n; i--; ) mp[p[i]] = 1;
		for(int i = n; i--; ) if(mp.find({p[i].x - 1, 1 - p[i].y}) != mp.end()) {
			if(mp.find({p[i].x + 1, 1 - p[i].y}) != mp.end()) ans++;
		}
		
		printf("%I64d\n", ans);
	}
	return 0;
}
