#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		int st, ed, flag = 1;
		cin>>ed, st = ed;
		while(--n) {
			int x; cin>>x;
			if(x == ed + 1) ed++;
			else if(x == st - 1) st--;
			else flag = 0;
		}
		if(flag == 1) puts("YES");
		else puts("NO");
	}
}
