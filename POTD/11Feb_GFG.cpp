//Equalize the Towers

class Solution {
  public:
  
    //fn to find the cost for same height 
    int Cost(vector<int>& heights, vector<int>& cost , int val){
        int costee =0;
        for(int i=0;i<heights.size();i++){
            costee+= abs(heights[i]-val)*cost[i];
        }
        return costee;
    }
    
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        // int minCost = INT_MAX;
        int low = *min_element(heights.begin(),heights.end());
        int high = *max_element(heights.begin(),heights.end());
        
        while(low<high){
            int mid = (low+high)/2;
            int costAtmid = Cost(heights,cost,mid);
            int costAtmid1 = Cost(heights,cost,mid+1);
            if(costAtmid>costAtmid1) {
                low = mid+1;
            }
            else{
                high = mid;
            }
            
        }
        return Cost(heights,cost,low);
    }
};
