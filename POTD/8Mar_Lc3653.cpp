//XOR After Range Multiplication Queries I
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9+7;
        int n = nums.size();
        int q = queries.size();
        vector<int>numsD = nums;
        for(int i=0;i<q;i++){
            vector<int>temp = queries[i];
            int idx = temp[0];
            while(idx<=temp[1]){
                numsD[idx]=(1LL*numsD[idx]*temp[3])%MOD;
                idx +=temp[2];
            }
            
        }
        int ans = 0;
        for(int x :numsD){
            ans^=x;
        }
        return ans;
    }
};