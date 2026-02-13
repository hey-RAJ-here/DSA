//All numbers with specific difference

class Solution {
  public:
    long long digitSum(long long x){
        long long sum =0;
        while(x>0){
            sum+= x%10;
            x = x/10;
        }
        return sum;
    }
    int getCount(int n, int d) {
        // code here
        long long ans = -1;
        long long left = 1;
        long long right = n;
        while(left<=right){
            long long mid = left + (right-left)/2;
            if(mid - digitSum(mid) >= d){
                ans = mid;
                right = mid-1;
                
            }
            else{
                left = mid+1;
            }
            
        }
        if(ans == -1)return 0;
        return n - ans +1;
    }
};