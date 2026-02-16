//Reverse Bits
class Solution {
public:
    int BtoD(string s){
        int n = s.size();
        long long ans =0;
        for(int i=31;i>=0;i--){
            ans+= (s[i]-'0')*(1LL <<(31-i));
        }
        return ans;
    }
    string IntToB(int d){
        string temp="";
        int l =d;
        while(l>0){
            temp.push_back(l%2 +'0');
            l/=2;
        }
        reverse(temp.begin(),temp.end());
        string tempL(32-temp.size(),'0');
        return tempL + temp;
    }
    int reverseBits(int n) {
        string binar = IntToB(n);
        reverse(binar.begin(),binar.end());
        return BtoD(binar);
    }
};