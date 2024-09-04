class Solution {
public:
    static const int NN = 55, MM = 2020, mod = 1e9 + 7;
    int dp[NN][NN][MM];
    int countOfPairs(vector<int>& vec) {
        for(int i = 0; i <= vec[0]; i++) {
            int j = vec[0] - i;
            dp[i][j][0] = 1;
        }
        for(int k = 0; k < vec.size() - 1; k++) {
            for(int i = 0; i <= vec[k]; i++) {
                int j = vec[k] - i;
                for(int I = i; I <= vec[k + 1]; I++) {
                    int J = vec[k + 1] - I;
                    if(j >= J) dp[I][J][k + 1] = (dp[I][J][k + 1] + dp[i][j][k]) % mod;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= vec.back(); i++) {
            int j = vec.back() - i;
            ans = (ans + dp[i][j][vec.size() - 1]) % mod;
        }
        return ans;
    }
};
