#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		vector<int> ans;
		while(n--) {
			string s; cin>>s;
			for(int i = 0; i < 4; i++) if(s[i] == '#') {
				ans.push_back(i + 1); break;
			}
		}
		for(int i = ans.size(); i--; ) printf("%d ", ans[i]); puts("");
	}
	return 0;
}
