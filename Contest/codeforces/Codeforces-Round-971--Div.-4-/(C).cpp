#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int x, y, k; scanf("%d %d %d", &x, &y, &k);
		
		x = (x + k - 1) / k;
		y = (y + k - 1) / k;
		
		if(x > y) printf("%d\n", x + x - 1);
		else printf("%d\n", y + y);
	}
	return 0;
}
