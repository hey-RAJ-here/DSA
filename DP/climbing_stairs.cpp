class Solution {
public:
    
    long long combinator(int n, int r) {
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
        }
        return res;
    }
    int climbStairs(int n) {
        int ans = 0;
        for (int i = 0; i <= n / 2; i++) {
            ans += combinator(n - i, i);
        }
        return ans;
    }
};