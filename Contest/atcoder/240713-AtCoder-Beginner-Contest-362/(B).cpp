#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

pii A, B, C;

int dist(pii a, pii b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int d[3];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %d %d %d %d %d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
	d[0] = dist(B, C);
	d[1] = dist(A, B);
	d[2] = dist(A, C);
	sort(d, d + 3);
	
	if(d[0] + d[1] == d[2]) puts("Yes");
	else puts("No");
	return 0;
}
