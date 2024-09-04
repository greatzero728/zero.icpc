#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 121;

bool flag[NN];
char s[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n, k; scanf("%d %d", &n, &k);
		for(int i = k; i--; ) flag[i] = 0;
		while(n--) {
			scanf("%s", s);
			int num = 0, I;
			for(int i = k; i--; ) if(s[i] == '1') num++, I = i;
			if(num == 1) flag[I] = 1;
		}
		bool ok = 1;
		for(int i = k; i--; ) if(!flag[i]) {
			ok = 0; break;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
