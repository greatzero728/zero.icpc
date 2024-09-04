#include<bits/stdc++.h>

using namespace std;

const int NN = 5050;

long long a[NN];
long long mx[NN][NN];
int L[NN], R[NN];

vector<long long> solution(int n, vector<int> arr, int q, vector<vector<int>> queries) {
	for(int i = 1; i <= n; i++) a[i] = arr[i - 1];
	for(int i = q; i--; ) {
		L[i] = queries[i][0], R[i] = queries[i][1];
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) mx[i][j] = 0;
	}
	for(int len = 1; len <= n; len++) {
		for(int ed = len; ed <= n; ed++) {
			int st = ed - len + 1;
			mx[st][ed] = max(mx[st][ed], a[ed]);
			if(len > 1) {
				long long val = max(mx[st][ed - 1], mx[st + 1][ed]);
				mx[st][ed] = max(mx[st][ed], val);
			}
		}
		for(int ed = n; ed > len; ed--) {
			a[ed] = a[ed - 1] ^ a[ed];
		}
	}
	
	vector<long long> ans;
	for(int i = 0; i < q; i++) {
		ans.push_back(mx[L[i]][R[i]]);
	}
	return ans;
}

int main() {
	
	vector<int> arr = {1, 2, 4, 8, 16, 32};
	vector<vector<int>> queries = {
		{1, 3},
		{2, 5},
		{1, 6}
	};
	arr = {3};
	queries = {
		{1, 1},
	};
	vector<long long> ans = solution(arr.size(), arr, queries.size(), queries);
	for(long long x : ans) cout<<x<<' '; puts("");
	return 0;
}
