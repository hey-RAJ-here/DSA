// Sort Integers by The Number of 1 Bits
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[] (int a , int b){
            int cnt1 = __builtin_popcount(a);
            int cnt2 = __builtin_popcount(b);
            //return no of 1s in binary repre

            if(cnt1==cnt2){
                return a<b;
            }
            return cnt1<cnt2;
        });
        return arr;
    }
};