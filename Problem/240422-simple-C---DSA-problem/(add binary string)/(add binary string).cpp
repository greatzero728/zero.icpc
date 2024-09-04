#include<bits/stdc++.h>

using namespace std;

string addBinary(string a, string b) {
	vector<int> s;
	for(int i = max(a.size(), b.size()) + 1; i--; ) {
		s.push_back(0);
	}
	
	reverse(a.begin(), a.end());
	for(int i = a.size(); i--; ) s[i] = a[i] - '0';
	
	reverse(b.begin(), b.end());
	for(int i = b.size(); i--; ) s[i] += b[i] - '0';
	
	for(int i = 0; i + 1 < s.size(); i++) {
		s[i + 1] += s[i] / 2, s[i] &= 1;
	}
	
	for(int i = s.size(); i--; ) if(s[i]) {
		string ans;
		for(int j = i; j >= 0; j--) ans += s[j] + '0';
		return ans;
	}
}

int main() {
	
	cout<<addBinary("1010", "1011")<<endl;
	return 0;
}
