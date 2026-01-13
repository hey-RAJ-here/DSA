//Separate Squares I

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        //apply binary search on lowest possible ans i.e low and highest possible ans i.e high
        double low = 1e18 ,  high = -1e18;
        //step1: find low and high
        for(auto&s : squares){
            double y = s[1];
            double slide = s[2];
            low = min(y,low);
            high = max(y+slide,high);
        }

        //step2: binary search on y coordinate
        for(int i=0;i<100;i++){
            double mid = (high+low)/2.0;
            double above = 0.0;
            double below = 0.0;

            //step3: compute f(mid);
            for(auto &s:squares){
                double y = s[1];
                double slide = s[2];
                double top = y+slide;

                //sq is completely above the mid line
                if(mid<=y){
                    above+= slide*slide;
                }
                //sq is completely below the mid line
                else if(mid>=top){
                    below += slide*slide;
                }
                //sq is cut by the mid line
                else{
                    above+= slide*(top-mid);
                    below += slide*(mid-y);
                }

            }
            //updation of high and low
            // above the line area is greater , mid ++
            if(below-above<0) low = mid;
            else high = mid;
        }
        return (high+low)/2.0;
    }
};