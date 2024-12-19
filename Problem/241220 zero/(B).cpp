#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

long getMaxThroughput(vector<int> host_throughput) {
    sort(host_throughput.begin(), host_throughput.end());
    
    long ans = 0;
    int n = host_throughput.size();
    int k = n / 3;
    for(int i = 0; i < k; i++) ans += host_throughput[n - 2 - 2 * i];
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    vector<int> zero = {2,3,4,3,4};
    zero = {4, 6, 3, 5, 4, 5};
    cout<<getMaxThroughput(zero)<<endl;
	return 0;
}
