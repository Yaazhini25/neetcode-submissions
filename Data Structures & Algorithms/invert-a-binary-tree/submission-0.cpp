class Solution {
public:
    void fn(TreeNode* root, TreeNode* p, TreeNode* q){
        root->left = q;
        root->right = p;
        if(p) fn(p, p->left, p->right);
        if(q) fn(q, q->left, q->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        fn(root, root->left, root->right);
        return root;
    }
};
