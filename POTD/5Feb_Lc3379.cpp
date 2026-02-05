// Transformed Array
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;
        for(int i=0 ;i<n;i++){
            int ind = nums[i];
            if(nums[i]>0){
                result.push_back(nums[(i+ind)%n]);
            }
            else if (nums[i]<0){
                // int pos = abs(i-ind)%n;
                int pos = (i - abs(ind))%n;
                if(pos<0)pos = n+pos;
                result.push_back(nums[pos]);
            }
            else{
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};