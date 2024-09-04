#include<bits/stdc++.h>

using namespace std;

const int NN = 202020;

int p[NN], ans[NN];
int vst[NN], runs;
char s[NN];

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", p + i);
		scanf("%s", s + 1);
		
		runs++;
		for(int i = 1; i <= n; i++) if(vst[i] != runs) {
			vector<int> vec;
			
			int num = 0;
			for(int u = i; vst[u] != runs; u = p[u]) {
				vst[u] = runs;
				vec.push_back(u);
				if(s[u] == '0') num++;
			}
			
			for(int j = 0; j < vec.size(); j++) ans[vec[j]] = num;
		}
		
		for(int i = 1; i <= n; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}
