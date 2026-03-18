//Distribute Candies

class Solution {
  public:
    
    int balance(Node* curr, int& total_moves){
        if(curr == NULL)return 0;
        
        int left_balance = balance(curr->left,total_moves);
        int right_balance = balance(curr->right,total_moves);
        
        total_moves += abs(left_balance) + abs(right_balance);
        return curr->data + left_balance + right_balance -1;
    }
    
    int distCandy(Node* root) {
        // code here
        int total_moves =0;
        balance(root,total_moves);
        return total_moves;
        
    }
};