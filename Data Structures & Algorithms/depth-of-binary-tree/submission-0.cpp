class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ls = maxDepth(root->left);
        int rs = maxDepth(root->right);
        return 1 + max(ls,rs);
    }
};
