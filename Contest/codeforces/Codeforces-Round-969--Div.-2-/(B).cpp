#include <bits/stdc++.h>

using namespace std;

int a[101010];

int main() {

	int t; scanf("%d", &t);
	while(t--) {
		int n, m; scanf("%d %d", &n, &m);
		for(int i = n; i--; ) scanf("%d", a + i);
		
		int mx = *max_element(a, a + n);
		while(m--) {
			char c; int l, r; scanf(" %c %d %d", &c, &l, &r);
			if(l <= mx && mx <= r) {
				if(c == '+') mx++;
				else mx--;
			}
			printf("%d ", mx);
		}
		puts("");
	}
	
	return 0;
}