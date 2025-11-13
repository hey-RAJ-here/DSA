#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int>&num){
        int n= num.size();
        int prev2 = 0;
        int prev = num[0];
        for(int i=1;i<n;i++){
            int pick = num[i];
            int nonpick = prev;
            if(i>1){
                pick += prev2;
            }
            int curri = max(pick,nonpick);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>num1;
        vector<int>num2;
        for(int i=0;i<nums.size();i++){
            if(i!=0)num1.push_back(nums[i]);
            if(i!=nums.size()-1)num2.push_back(nums[i]);
            
        }
        return max(solve(num1),solve(num2));
    }
};