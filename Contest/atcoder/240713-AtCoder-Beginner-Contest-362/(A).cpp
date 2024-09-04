#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int R, G, B; scanf("%d %d %d", &R, &G, &B);
	string s; cin>>s;
	
	int ans;
	if(s[0] == 'R') ans = min(G, B);
	else if(s[0] == 'G') ans = min(R, B);
	else ans = min(G, R);
	cout<<ans<<endl;
	return 0;
}
