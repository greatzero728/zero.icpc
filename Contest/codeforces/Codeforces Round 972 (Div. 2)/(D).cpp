#include<bits/stdc++.h>

using namespace std;

const int NN = 1010;

char s[NN];
int dp[5], tmp[5];
int vec[NN], nn;

int main() {
    
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        for(int i = 5; i--; ) dp[i] = -1e9;
        dp[4] = 0;
        while(n--) {
            cin>>s;
            
            nn = 0;
            int n = strlen(s);
            for(int i = 0; i < n; i++) {
                if(s[i] == 'n') vec[nn++] = 0;
                if(s[i] == 'a') vec[nn++] = 1;
                if(s[i] == 'r') vec[nn++] = 2;
                if(s[i] == 'e') vec[nn++] = 3;
                if(s[i] == 'k') vec[nn++] = 4;
            }
            
            for(int i = 5; i--; ) tmp[i] = dp[i];
            
            for(int ed = 5; ed--; ) {
                int num = 0;
                for(int i = 0, c = ed; i < nn; i++) {
                    if(vec[i] == (c + 1) % 5) {
                        c = (c + 1) % 5;
                        if(c == 4) num += 10;
                    }
                    tmp[c] = max(tmp[c], dp[ed] + num - nn);
                }
            }
            for(int i = 5; i--; ) dp[i] = tmp[i];
        }
        cout<< *max_element(dp, dp + 5) << endl;
    }
}
