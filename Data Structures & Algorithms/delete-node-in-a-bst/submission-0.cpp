class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else{  //root is the key to be removed
            //1. no left  (single right or no children)
            if(!root->left){
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            //2. no right
            if(!root->right){
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            //3. two children
            TreeNode* succ = root->left;
            while(succ->right) succ = succ->right;
            root->val = succ->val;
            root->left = deleteNode(root->left, root->val);
        }
        return root;
    }
};