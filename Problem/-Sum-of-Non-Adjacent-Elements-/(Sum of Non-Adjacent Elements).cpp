#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int maxNonAdjacentSum(vector<int> vec) {
	vector<int> mx = vec;
	for(int i = 0; i < vec.size(); i++) {
		if(i) mx[i] = max(mx[i - 1], vec[i]);
		if(i > 1) mx[i] = max(mx[i], mx[i - 2] + vec[i]);
	}
	int ans = mx[0];
	for(int i = 1; i < mx.size(); i++) ans = max(ans, mx[i]);
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
//	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	
	return 0;
}
