#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int a[202020];

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
	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) a[i] = 0;
		
		if(n % 3 == 2) {
			if(ok(n + 1)) {
				for(int i = 1; i <= n; i++) a[i] = n + 1 - i;
			}
			else {
				for(int i = 1; i < n; i++) a[i] = n - i;
				a[n] = n;
			}
		}
		else {
			for(int i = 2; i < n; i += 3) {
				int x = i - 1, y = i, z = i + 1;
				if(ok(x + x) && ok(y + y) && ok(z + z)) a[x] = x, a[y] = y, a[z] = z;
				if(ok(x + x) && ok(y + z) && ok(z + y)) a[x] = x, a[y] = z, a[z] = y;
				if(ok(x + y) && ok(y + x) && ok(z + z)) a[x] = y, a[y] = x, a[z] = z;
				if(ok(x + y) && ok(y + z) && ok(z + x)) a[x] = y, a[y] = z, a[z] = x;
				if(ok(x + z) && ok(y + x) && ok(z + y)) a[x] = z, a[y] = x, a[z] = y;
				if(ok(x + z) && ok(y + y) && ok(z + x)) a[x] = z, a[y] = y, a[z] = x;
			}
			if(n % 3 == 1) a[n] = n;
		}
		
//		cout<<"n = "<<n<<endl;
		for(int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
//			if(!ok(i + a[i])) printf("0 ");
//			else printf("%d ", i + a[i]);
		}
		puts("");
	}
	return 0;
}
