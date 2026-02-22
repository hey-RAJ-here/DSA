//Binary Gap
class Solution {
public:
    string intToB(int n){
        string ans="";
        while(n>0){
            ans.push_back(n%2+'0');
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int binaryGap(int n) {
        string Bin = intToB(n);
        //find first 1 in Bin
        bool found = false;
        int first ;
        for(int i=0;i<Bin.size();i++){
            if(Bin[i]=='1'){
                found = true;
                first = i;
                break;
            }
        }
        if(found==false)return 0;
        int maxdiff = INT_MIN;
        int start = first;
        for(int j =first +1;j<Bin.size();j++){
            if(Bin[j]=='1'){
                int diff = (j-first);
                maxdiff = max(maxdiff,diff);
                first = j;
            }
            
        }
        if(maxdiff==INT_MIN)return 0;
        return maxdiff;
    }
};