#include<bits/stdc++.h>

using namespace std;

const int NN = 202020;

char s[NN];

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		scanf("%s", s);
		
		int id = -1;
		for(int i = 0; s[i]; i++) if(s[i] == '0') {
			id = i; break;
		}
		int c = id - 1;
		
		if(~id) {
			if(1 <= c) {
				if(n % c) puts("No");
				else {
					int r = n / c;
					if(r != c) puts("No");
					else {
						bool ok = 1;
						for(int i = 0, nn = 0; i < r; i++) {
							for(int j = 0; j < c; j++) {
								char x = '0';
								if(i == 0 || i == r - 1) x = '1';
								if(j == 0 || j == c - 1) x = '1';
								if(s[nn++] != x) ok = 0;
							}
						}
						if(ok) puts("Yes");
						else puts("No");
					}
				}
			}
			else puts("No");
		}
		else if(n == 1) puts("Yes");
		else if(n == 4) puts("Yes");
		else puts("No");
	}
	return 0;
}
