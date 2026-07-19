class Solution {
public:
    int geth(TreeNode* root){
        if(!root) return 0;
        int lh = geth(root->left);
        int rh = geth(root->right);
        if(lh<0 || rh<0 || abs(lh-rh)>1) return -1;
        return 1 + max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return geth(root)!=-1;
    }
};
