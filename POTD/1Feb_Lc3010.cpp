// Divide an Array Into Subarrays With Minimum Cost I
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int minSum = nums[0];
        int n = nums.size();
        auto it  = min_element(nums.begin()+1,nums.end());
        int min1 = *it;
        int min1I = it - nums.begin();
        int min2 = INT_MAX;
        for(int i=1;i<n;i++){
            if(i != min1I){
                min2 = min(min2,nums[i]);
            }
        }
        minSum += min1 +min2 ;
        return minSum;

    }
};