//Count Subarrays with given XOR

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mpp;
        int prefixXor =0;
        long cnt =0;
        mpp[0]=1;
        for(int i=0;i<arr.size();i++){
            prefixXor ^=arr[i];
            int needed = prefixXor^k;
            if(mpp.find(needed)!=mpp.end()){
                cnt+=mpp[needed];
            }
            mpp[prefixXor]++;
        }
        return cnt;
    }
};