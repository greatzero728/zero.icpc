#include<bits/stdc++.h>

using namespace std;

long long a[101010];

int main() {
	
	int t; cin>>t;
	while(t--) {
		long long l, r; cin>>l>>r;
		
		if(l == r) puts("1");
		else {
			int n = 0;
			a[++n] = l, a[++n] = l + 1;
			while(true) {
				long long dif = a[n] - a[n - 1] + 1;
				a[n + 1] = a[n] + dif;
				if(a[n + 1] > r) break;
				n++;
			}
			printf("%d\n", n);
		}
	}
	return 0;
}
