//Form the Largest Number
class Solution {
  public:
  
    static bool compare(string& s1 , string& s2){
        if(s1+s2 >s2+s1)return true;
        return false;
    }
    string findLargest(vector<int> &arr) {
        // code here
        vector<string>s;
        for(int x:arr){
            s.push_back(to_string(x));
        }
        sort(s.begin(),s.end(),compare);
        string ans="";
        if(s[0]=="0")return "0";
        for(auto x :s){
            ans+=x;
        }
        return ans;
    }
};