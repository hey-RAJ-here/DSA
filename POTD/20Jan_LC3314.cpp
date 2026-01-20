//  Construct the Minimum Bitwise Array I
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++){
            bool milgya = false;
            int size = nums[i];
            for(int j=1;j<size;j++){
                if((j|(j+1))==size){
                    ans.push_back(j);
                    milgya = true;
                    break;
                    
                }
            
            }
            if(milgya == false) ans.push_back(-1);
            
        }
        return ans;
    }
};