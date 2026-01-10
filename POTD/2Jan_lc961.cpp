//N-Repeated Element in Size 2N Array

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n= nums.size();
        // sort(nums.begin(),nums.end());
        // app1
        // // for(int i=0;i<n+2;i++){
        // //     if(nums[i+1]==nums[i]){
        // //         return nums[i];
        // //     }
        // // }
        // // return 1;
        //app2
        // if(n==2)return nums[0];
        // int mid =(n-1)/2;
        // if(nums[mid]==nums[mid-1]) return nums[mid];
        // else return nums[mid+1];
        // return 1;
        
        //approach 3
        for (int i = 0; i < n - 1; i++) {
            if (i + 1 < n && nums[i] == nums[i + 1]) return nums[i];
            if (i + 2 < n && nums[i] == nums[i + 2]) return nums[i];
            if (i + 3 < n && nums[i] == nums[i + 3]) return nums[i];
        }
        return -1;
    }
};