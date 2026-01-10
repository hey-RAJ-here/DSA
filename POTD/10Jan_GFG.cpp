class Solution {
  public:
  
    int atmostk(string &s, int k ){
        int l = 0;
        int ans=0;
        int distinct =0;
        vector<int>freq(26,0);
        for(int r=0;r<s.size();r++){
            if(freq[s[r]-'a']==0){
                
                distinct++;
            }
            freq[s[r]-'a']++;
            while(distinct>k){
                freq[s[l]-'a']--;
                if(freq[s[l]-'a']==0){
               
                distinct--;
                }
                 l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here
        return atmostk(s,k)-atmostk(s,k-1);
    }
};