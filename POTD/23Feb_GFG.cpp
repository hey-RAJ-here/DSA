//Union of Arrays with Duplicates
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>dist;
        for(int x:a){
            dist.insert(x);
        }
        for(int y:b){
            dist.insert(y);
        }
        vector<int>ans;
        for(auto &z:dist){
            ans.push_back(z);
        }
        return ans;
    }
};