#include <bits/stdc++.h>
using namespace std;

// memoization 
// time complexity : O(n*k)
// space complexity : O(n) + O(n)  (dp array + recursive stack space)
class Solution {
public:

    int solve(int ind , vector<int>&heights , vector<int>&dp ,int k){
        if(ind ==0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int mstep =INT_MAX;
        for(int i=1;i<=k;i++){
            if(ind-i >=0){
                int jump = solve(ind-i,heights,dp,k)+ abs(heights[ind]-heights[ind-i]);
                mstep=min(mstep,jump);
            }
            
        }
        return dp[ind]=mstep;
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int>dp(n,-1);
        return solve(n-1,heights,dp,k);
    }
};
