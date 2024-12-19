#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;




bool ok(string a, string b) {
    if(a == b) return true;
    for(int i = 1; i < a.size(); i++) {
        string c = a;
        swap(c[i - 1], c[i]);
        if(c == b) return true;
    }
    return false;
}

int findSimilar(string keyword, string review) {
    int ans = 0;
    int m = keyword.size();
    for(int i = m - 1; i < review.size(); i++) {
        string zero;
        for(int j = 0; j < m; j++) zero += review[i - m + 1 + j];
        if(ok(keyword, zero)) ans++;
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    cout<<findSimilar("aaa", "aaaa")<<endl;
	return 0;
}
