class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> stk;
        TreeNode* curr;
        stack<int> res;
        vector<int> ans;
        stk.push(root);
        while(!stk.empty()){
            curr = stk.top(); stk.pop();
            res.push(curr->val);
            if(curr->left) stk.push(curr->left);
            if(curr->right) stk.push(curr->right);
        }
        while(!res.empty()){
            ans.push_back(res.top()); res.pop();
        }
        return ans;
    }
};