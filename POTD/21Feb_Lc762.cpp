//Prime Number of Set Bits in Binary Representation
class Solution {
public:
    bool checkPrime(string b){
        int cnt =0;
        for(char c: b){
            if(c=='1')cnt++;
        }
        if(cnt<=1)return false;
        for(int i=2;i*i<=cnt;i++){
            if(cnt%i == 0)return false;
        }
        return true;
    }

    string intToB(int n){
        string B ="";
        while(n>0){
        B.push_back(n%2 +'0');
        n/=2;
        }
        return B;
    }
    int countPrimeSetBits(int left, int right) {
        int ans =0;
        string temp;
        for(int j=left ;j<=right;j++){
            temp = intToB(j);
            if(checkPrime(temp))ans++;
        }
        return ans;
    }
};