class Solution {
public:
    void fn(TreeNode* root, int val){
        if(val < root->val){
            if(!root->left) {root->left = new TreeNode(val); return;}       
            fn(root->left, val);
        }
        else{
            if(!root->right) {root->right = new TreeNode(val); return;}
            fn(root->right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        fn(root, val);
        return root;
    }
};