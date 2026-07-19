class Solution {
public:
    vector<TreeNode*> ps;
    TreeNode* findnode(TreeNode* root, TreeNode* subRoot){
        if(!root) return nullptr;
        if(root->val == subRoot->val) {ps.push_back(root); } 
        TreeNode* l = findnode(root->left, subRoot);
        TreeNode* r = findnode(root->right, subRoot);
        if(l) return l;
        return r;
    }
    bool sametree(TreeNode* p, TreeNode* q){
        if(p==nullptr || q==nullptr) return p==q;
        return (p->val == q->val) && sametree(p->left, q->left) && sametree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        findnode(root, subRoot);
        for(auto p: ps){
            if(sametree(p,subRoot)) return true;
        }
        return false;
    }
};
