class Solution {
public:
    bool sametree(TreeNode* p, TreeNode* q){
        if(p==nullptr || q==nullptr) return p==q;
        return (p->val == q->val) && sametree(p->left, q->left) && sametree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(sametree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
