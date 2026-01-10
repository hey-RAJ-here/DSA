//Max Xor Subarray of size K

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int xr = 0;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(i<k){
                xr = xr ^ arr[i];
            }
            else{
                xr = xr ^ arr[i] ^ arr[i-k];
            }
            if (i>=k-1) {
                ans = max(ans,xr);
            }
        }
        return ans;
    }
};