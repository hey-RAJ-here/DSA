#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // memorisation 
    // int f(int ind, vector<int>&nums , vector<int>&dp){

    //     if(ind ==0 )return nums[0];
    //     if(ind ==1)return max(nums[0], nums[1]);
    //     if(dp[ind]!=-1)return dp[ind];
    //     // int maxMon = INT_MIN;
    //     // for(int i=2;i<=ind;i++){
    //     //    int  money = f(ind-i,nums,dp)+nums[ind-i];
    //     //     maxMon = max(maxMon,money);
    //     // }
    //     // return dp[ind]=maxMon;
    //     int pick = nums[ind]+f(ind-2,nums,dp);
    //     int skip = f(ind-1,nums,dp);
    //    return  dp[ind ]= max(pick,skip);

    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];

    // tabulation
       vector<int>dp(n,-1);

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i =2;i<n;i++){
            int pick = dp[i-2]+nums[i];
            int skip = dp[i-1];
            dp[i]=max(pick,skip);
        }
        return dp[n-1];

    //    memorization
    //    return f(n-1,nums,dp);
     }
};