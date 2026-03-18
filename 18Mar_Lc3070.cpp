//Count Submatrices with Top-Left Element and Sum Less Than k
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt =0;
        vector<vector<int>>pref(m,vector<int>(n)) ;
        for(int i=0 ; i<m;i++){
            for(int j=0;j<n;j++){
                pref[i][j] = grid[i][j];

                if(i>0) pref[i][j]+=pref[i-1][j];
                if(j>0) pref[i][j]+=pref[i][j-1];
                if(i>0 && j>0) pref[i][j]-=pref[i-1][j-1];

                if(pref[i][j]<=k)cnt++;
            }
        }
        return cnt;
    }
};