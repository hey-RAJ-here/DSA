class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int>ans;
        deque<int>d;
        for(int i=0;i<arr.size();i++){
            
            //remove from front
            if(!d.empty()&& d.front() == i-k){
                d.pop_front();
            }
            //remove the smaller dq element if next element found is larger
            while(!d.empty() && arr[d.back()]<=arr[i]){
                d.pop_back();
            }
            d.push_back(i);
            
            if(i>=k-1){
                ans.push_back(arr[d.front()]);
            }
        }
        return ans;
    }
};