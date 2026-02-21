//Find H-Index

class Solution {
  public:
    int hIndex(vector<int>& citations) {

        sort(citations.begin(), citations.end());
        int n = citations.size();

        int i = 0;
        int ans = 0;
        int unq, cnt;

        while(i < n){

            unq = citations[i];
            cnt = n - i;

            ans = max(ans, min(unq, cnt));   

            i++;
        }

        return ans;
    }
};