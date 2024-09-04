#include<bits/stdc++.h>

using namespace std;

const int NN = 2e5+7;

int a[NN];
long long dp[NN];
char s[NN];
vector<int> st, ed;

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; cin>>n;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]), dp[i] = dp[i - 1] + a[i];
		}
		scanf("%s", s + 1);
		
		st.clear();
		for(int i = n; i; i--) if(s[i] == 'L') st.push_back(i);
		ed.clear();
		for(int i = 1; i <= n; i++) if(s[i] == 'R') ed.push_back(i);
		
		long long ans = 0;
		while(!st.empty() && !ed.empty()) {
			int L = st.back(), R = ed.back();
			st.pop_back(), ed.pop_back();
			if(L > R) break;
			if(L <= R) ans += dp[R] - dp[L - 1];
		}
		cout<<ans<<endl;
	}
}
