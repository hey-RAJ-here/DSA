//Minimum Deletions to Make String Balanced
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int a = 0;
        int b = 0;
        int cnt =0;
        for(char c:s){
            if(c=='a')a++; 
        }
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a--;
                // if((a-b)<-1)cnt++;
                 cnt = min(cnt + 1, b);
            }
            else{
                // if((b-a)<-1)cnt++;
                 b++;
            }
        }
        return cnt;
    }
};