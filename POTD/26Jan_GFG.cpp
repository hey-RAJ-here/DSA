//Generate Permutations of an array


class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        do{
            ans.push_back(arr);
        }
        while(next_permutation(arr.begin(),arr.end()));
        return ans;
    }
};