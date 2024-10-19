class Solution {
public:
    int dp[10009];  
    Solution() {
        memset(dp, -1, sizeof(dp)); 
    }

    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1; 
        int &ans = dp[n];
        if(ans != -1) return ans;
        return ans = (tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3));
        }
};
