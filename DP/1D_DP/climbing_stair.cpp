class Solution {

    // //recursive solution
    //t.c - O(2^n)
    // int recur(int ind){
    //     if(ind==0 || ind ==1)return 1;
    //     return recur(ind-1)+ recur(ind-2);
        
    // }
    //dp with memorisation



public:
    
    
    int climbStairs(int n) {
    //recursive
    // return recur(n);

    //dp with tabulation
    //t.c- O(n)
    //s.c - O(n);
    // vector<int>dp(n+1,-1);
    // dp[0]=1;
    // dp[1]=1;
    // for(int i=2;i<=n;i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    // }
    // return dp[n];

    //more space optimised
    //t.c- O(n);
    //s.c - O(1);

    int prev=1,prev2=1;
    int curri;
    for(int i=2;i<=n;i++){
        curri = prev+prev2;
        prev2=prev;
        prev = curri;
        
    } 
    return prev;
    }
};