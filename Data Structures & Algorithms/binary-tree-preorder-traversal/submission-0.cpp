class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> stk;
        stk.push(root);
        vector<int> ans;
        TreeNode* curr;
        while(!stk.empty()){
            curr =  stk.top(); stk.pop();
            ans.push_back(curr->val);
            if(curr->right) stk.push(curr->right);
            if(curr->left) stk.push(curr->left);
        }
        return ans;
    }
};