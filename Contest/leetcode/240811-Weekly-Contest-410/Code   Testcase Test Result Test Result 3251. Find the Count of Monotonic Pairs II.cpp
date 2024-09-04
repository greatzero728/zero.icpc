class Solution {
public:
    static const int NN = 1010, MM = 2020, mod = 1e9 + 7;
    int dp[NN][MM];

    int countOfPairs(vector<int>& vec) {
        for(int i = 0; i <= vec[0]; i++) dp[i][0] = 1;
        int n = vec.size();

        for(int k = 0; k < n - 1; k++) {
            for(int i = 0; i <= vec[k]; i++) {
                int j = vec[k] - i;
                int st = max(i, vec[k + 1] - j), ed = vec[k + 1];
                dp[st][k + 1] = (dp[st][k + 1] + dp[i][k]) % mod;
                dp[ed + 1][k + 1] = (dp[ed + 1][k + 1] - dp[i][k] + mod) % mod;
            }
            for(int i = 1; i <= vec[k + 1]; i++) {
                dp[i][k + 1] = (dp[i][k + 1] + dp[i - 1][k + 1]) % mod;
            }
        }
        int ans = 0;
        for(int i = 0; i <= vec.back(); i++) {
            ans = (ans + dp[i][n - 1]) % mod;
        }
        return ans;
    }
};
