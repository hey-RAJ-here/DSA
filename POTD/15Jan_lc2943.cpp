//Maximize Area of Square Hole in Grid
//level- medium
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
      
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int area =0;
        int maxheight=1 ;
        int maxwidth=1;
        int cnt=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1] == 1){
                cnt++;
                maxheight = max (cnt,maxheight);
            }
            else cnt=1;
        }
        cnt=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1] == 1){
                cnt++;
                maxwidth = max (cnt,maxwidth);
            }
            else cnt=1;
        }
        int size = min(maxheight+1,maxwidth+1);
        return size*size;
    }
};