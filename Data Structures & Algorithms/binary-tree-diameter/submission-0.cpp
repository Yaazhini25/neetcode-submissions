class Solution {
public:
    int fn(TreeNode* root, int& ans){
        if(!root) return 0;
        int lh = fn(root->left, ans);
        int rh = fn(root->right, ans);
        ans = max(ans, lh+rh);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        fn(root, ans);
        return ans;
    }
};
