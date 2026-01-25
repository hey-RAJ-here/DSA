//Minimum Difference Between Highest and Lowest of K Scores
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if((i+k)<=nums.size()){
            int diff = nums[i+k-1]-nums[i];
            ans = min(ans,diff);
            }
        }
        return ans;
    }
};