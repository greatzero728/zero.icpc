#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 10101010;

int fail[NN]; //0-index
void build_fail(string s) {
	int n = s.size();
	for(int i = 0, b = fail[0] = -1; ++i < n; fail[i] = b) {
		while(~b && s[b + 1] ^ s[i]) b = fail[b];
		if(s[b + 1] == s[i]) b++;
	}
}

bool match(string t, string s) {
	int n = s.size(), m = t.size();
	for(int i = 0, b = -1; i < n; i++) {
		while(~b && t[b + 1] ^ s[i]) b = fail[b];
		if(t[b + 1] == s[i]) b++;
		if(b == m - 1) {
			return true;
			//s[i - m + 1, i] is same as t
			b = fail[b];
		}
	}
	return false;
}

bool containsSubstring(string a, string b) {
	build_fail(b);
	return match(b, a);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
//	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	cout<<containsSubstring("Hello world", "world")<<endl;
	return 0;
}
