// Maximum Product of Splitted Binary Tree

class Solution {
public:
    long long MOD = 1e9 + 7;
    long long ans = 0;

    // pass 1: total sum
    long long getTotalSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + getTotalSum(node->left) + getTotalSum(node->right);
    }

    // pass 2: compute currSum + product
    long long dfs(TreeNode* node, long long totalSum) {
        if (!node) return 0;

        long long leftSum = dfs(node->left, totalSum);
        long long rightSum = dfs(node->right, totalSum);

        long long currSum = node->val + leftSum + rightSum;

        long long product = currSum * (totalSum - currSum);
        ans = max(ans, product);

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        long long totalSum = getTotalSum(root);
        dfs(root, totalSum);
        return ans % MOD;
    }
};
