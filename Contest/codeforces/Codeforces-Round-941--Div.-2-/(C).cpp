#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int a[NN];
bool b[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		n = unique(a + 1, a + n + 1) - a - 1;
		
		for(int i = n; i > 1; i--) a[i] -= a[i - 1];
		
		b[n] = 1;
		for(int i = n - 1; i; i--) {
			if(!b[i + 1]) b[i] = 1;
			else {
				if(a[i] > 1) b[i] = 1;
				else b[i] = 0;
			}
		}
		
		if(b[1]) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
