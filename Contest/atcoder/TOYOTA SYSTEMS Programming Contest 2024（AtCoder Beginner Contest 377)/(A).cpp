#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    string s; cin>>s;
    sort(s.begin(), s.end());
    if(s == "ABC") puts("Yes");
    else puts("No");
	return 0;
}
