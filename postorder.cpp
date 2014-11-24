class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int > out;
        if(root == nullptr) return out;
        stack<TreeNode *> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* cur = nodes.top();
            nodes.pop();
            out.push_back(cur->val);
            if(cur->left) nodes.push(cur->left);
            if(cur->right) nodes.push(cur->right);
        }
        reverse(out.begin(), out.end());
        return out;
    }
};
