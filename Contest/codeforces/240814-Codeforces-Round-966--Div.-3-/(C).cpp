#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 202020;

int nn;
int arr[NN], a[NN], b[NN], vst[NN];
char s[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", a + i);
		
		nn = 0;
		for(int i = n; i--; ) arr[nn++] = a[i];
		sort(arr, arr + nn), nn = unique(arr, arr + nn) - arr;
		for(int i = 0; i < n; i++) a[i] = lower_bound(arr, arr + nn, a[i]) - arr;
		
		for(int i = nn; i--; ) vst[i] = -1;
		nn = 0;
		for(int i = 0; i < n; i++) {
			if(vst[a[i]] == -1) vst[a[i]] = ++nn, a[i] = nn;
			else a[i] = vst[a[i]];
		}
		
		int m; scanf("%d", &m);
		while(m--) {
			scanf("%s", s);
			if(strlen(s) != n) puts("NO");
			else {
				nn = 0;
				for(int i = n; i--; ) arr[nn++] = s[i] - 'a';
				sort(arr, arr + nn), nn = unique(arr, arr + nn) - arr;
				for(int i = 0; i < n; i++) b[i] = lower_bound(arr, arr + nn, s[i] - 'a') - arr;
				
				for(int i = nn; i--; ) vst[i] = -1;
				nn = 0;
				bool flag = 1;
				for(int i = 0; i < n; i++) {
					if(vst[b[i]] == -1) vst[b[i]] = ++nn, b[i] = nn;
					else b[i] = vst[b[i]];
					if(a[i] != b[i]) flag = 0;
				}
				
				if(flag) puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}
