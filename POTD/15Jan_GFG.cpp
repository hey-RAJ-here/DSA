// Candy
// Difficulty: Hard

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>candies(n,1);
        
        //left to right 
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }
        //right to left
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                candies[i]=max(candies[i],candies[i+1]+1);
            }
        }
        return accumulate(candies.begin(),candies.end(),0);
    }
};

