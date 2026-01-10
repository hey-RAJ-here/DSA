
//Maximum Level Sum of a Binary Tree
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        //base cnd - 
        if(root==NULL)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int bestLevel = 1;
        int level =1;
        int maxSum = INT_MIN;
        int sum;
        while(!q.empty()){
            //starting a new level
            int size = q.size();
            sum =0;
            for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            sum+=node->val;
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            }
            if (sum>maxSum){
                maxSum = sum;
                bestLevel = level;
            }
            level++;
        }
        return bestLevel;
    }
};