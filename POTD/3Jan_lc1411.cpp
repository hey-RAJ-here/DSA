class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 +7;
        long same = 6;//ABA Type
        long diff = 6;//ABC Type

        for(int i=2;i<=n;i++){
            //if previous row is same - nof of way to make same is 3
            //if prv row is diff type - no of way to make it same is 2
            long newSame = (same*3+ diff*2)%MOD;
            //similarly , 
             //if previous row is same - nof of way to make diff is 2
            //if prv row is diff type - no of way to make it diff is 2
            long newDiff = (same*2 + diff*2)%MOD;
            same = newSame;
            diff = newDiff;
        }
        return (same+diff)%MOD;
    }
};