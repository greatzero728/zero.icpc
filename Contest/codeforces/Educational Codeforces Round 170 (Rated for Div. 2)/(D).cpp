#include<bits/stdc++.h>

using namespace std;

const int NN = 2020202, MM = 5050;

int a[NN];
vector<int> vec[2][MM];
int dp[MM][MM], num[2];

int main() {
    
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    
    int N = 0;
    for(int i = 1, j = 1; i <= n; i = j) {
        for(; j <= n && (a[i] == 0) == (a[j] == 0); j++);
        if(i == 1 && a[i] != 0) continue;
        if(a[i] == 0) N += j - i;
        else {
            for(int k = i; k < j; k++) vec[a[k] > 0][N].push_back(abs(a[k]));
            for(int k = 2; k--; ) sort(vec[k][N].begin(), vec[k][N].end());
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= i; j++) {
            num[1] = j, num[0] = i - num[1];
            if(j) {
                dp[i][j] = dp[i - 1][j - 1];
                for(int k = 2; k--; ) {
                    dp[i][j] += upper_bound(vec[k][i].begin(), vec[k][i].end(), num[k]) - vec[k][i].begin();
                }
            }
            
            if(i - j) {
                int tmp = dp[i - 1][j];
                for(int k = 2; k--; ) {
                    tmp += upper_bound(vec[k][i].begin(), vec[k][i].end(), num[k]) - vec[k][i].begin();
                }
                dp[i][j] = max(dp[i][j], tmp);
            }
        }
    }
    int mx = 0;
    for(int i = 0; i <= N; i++) mx= max(mx, dp[N][i]);
    cout<<mx<<endl;
	return 0;
}
