//Construct Product Matrix
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long p =1;
        // vector<vector<int>> prefP(n,vector<int>(m));
        vector<vector<int>> suffP(n,vector<int>(m));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                // p *= grid[i][j];
                // if(grid[i][j]%12345 ==0){
                //     suffP[i][j]=(p/12345);
                // }
                // p%=12345;
                suffP[i][j] = p ;
                p = (p*grid[i][j])%12345;
                
            }
        }
        
        vector<vector<int>> ans(n,vector<int>(m));
        p=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // if(grid[i][j]%12345 ==0 )ans[i][j] = suffP[i][j];
                // else ans[i][j]=p/grid[i][j];
                ans[i][j]= (p*suffP[i][j])%12345;
                p= (p*grid[i][j])%12345;
            }
        }
        return ans;
    }
};