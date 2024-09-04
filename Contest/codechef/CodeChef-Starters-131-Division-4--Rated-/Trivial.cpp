#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

bool ok(int n) {
	while(n) {
		if(n % 3 == 2) return true;
		n /= 3;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	
	for(int i = 1; i <= 100; i++) {
		if(ok(i)) cout<<i<<' ';
	}
	puts("");
	for(int i = 1; i <= 100; i++) {
		if(!ok(i)) cout<<i<<' ';
	}
	return 0;
}
