#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

char s[121];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%s", s);
		if(strlen(s) < 3) puts("NO");
		else if(s[0] == '1' && s[1] == '0') {
			if(s[3]) {
				if(s[2] != '0') {puts("YES"); continue;}
			}
			else {
				if(s[2] >= '2') {puts("YES"); continue;}
			}
			puts("NO");
		}
		else puts("NO");
	}
	return 0;
}
