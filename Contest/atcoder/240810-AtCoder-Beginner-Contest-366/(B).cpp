#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 121;

char s[NN][NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	
	for(int j = 1; j <= 100; j++) {
		string c;
		for(int i = n; i >= 1; i--) {
			if(s[i][j]) c += s[i][j];
			else c += '*';
		}
		while(!c.empty() && c.back() == '*') c.pop_back();
		if(!c.empty()) cout<<c<<endl;
	}
	return 0;
}
