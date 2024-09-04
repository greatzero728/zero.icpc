#include<bits/stdc++.h>

using namespace std;

const int NN = 2e5+7;

int temp[NN], a[NN], flaged[NN];
int b[NN];
char s[NN];

int main() {
	
	int t; cin>>t;
	for(int k = 0; k < t; k++) {
		int n, nn = 0;
		cin>>n;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			temp[nn++] = a[i];
		}
		sort(temp, temp + nn);
		nn = unique(temp, temp + nn) - temp;
		for(int i = 0; i < n; i++) {
			a[i] = lower_bound(temp, temp + nn, a[i]) - temp;
		}
		
		for(int i = nn; i--; ) flaged[i] = -1;
		nn = 0;
		for(int i = n; i--; ) {
			if(flaged[a[i]] == -1) {
				flaged[a[i]] = ++nn, a[i] = nn;
			}
			else a[i] = flaged[a[i]];
		}
		
		int m;
		cin>> m;
		for(int kk = 0; kk < m; kk++) {
			scanf("%s", s);
			if(strlen(s) != n) puts("NO");
			else {
				nn = 0;
				for(int i = n; i--; ) temp[nn++] = s[i] - 'a';
				sort(temp, temp + nn);
				nn = unique(temp, temp + nn) - temp;
				for(int i = n; i--; ) b[i] = lower_bound(temp, temp + nn, s[i] - 'a') - temp;
				
				
				for(int i = nn; i--; ) flaged[i] = -1;
				nn = 0;
				bool flag = 1;
				for(int i = n; i--; ) {
					if(flaged[b[i]] == -1) flaged[b[i]] = ++nn, b[i] = nn;
					else b[i] = flaged[b[i]];
					
					if(a[i] != b[i]) {flag = 0; break;}
				}
				if(flag) puts("YES");
				else puts("NO");
			}
		}
	}
}
