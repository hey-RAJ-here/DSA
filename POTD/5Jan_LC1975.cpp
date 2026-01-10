//maximum matrix sum
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum =0;
        int negCnt=0;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0)negCnt++;
                sum+=abs(matrix[i][j]);
                mini = min(abs(matrix[i][j]),mini);
            }
        }
        if(negCnt%2!=0){
            sum-=2*mini;
        }
        return sum;
    }
};