//Segregate 0s and 1s
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int cnt0=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)cnt0++;
        }
        // cnt1 = arr.size()-cnt0;
        
        for(int i=0;i<cnt0;i++ ){
            arr[i]=0;
        }
        for(int j=cnt0;j<arr.size();j++){
            arr[j]=1;
        }
    }
};