// Interleave the First Half of the Queue with Second Half

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        queue<int>leftH;
        queue<int>rightH;
        while(q.size()>n/2){
            leftH.push(q.front());
            q.pop();
        }
        while(!q.empty()){
            rightH.push(q.front());
            q.pop();
        }
        while(q.size()!=n){
            q.push(leftH.front());
            leftH.pop();
            q.push(rightH.front());
            rightH.pop();
        }
        
    }
};