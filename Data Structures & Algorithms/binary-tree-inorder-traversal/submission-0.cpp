class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        vector<int> ans;
        while(curr || !stk.empty()){
            while(curr){
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top(); stk.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};