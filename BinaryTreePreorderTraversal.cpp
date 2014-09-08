/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> out;
        if(root == nullptr ) return out;
        list< TreeNode *> tree;
        TreeNode * temp = root;
        tree.push_front(temp);
        while (tree.size() > 0){
            temp = tree.front();
            tree.pop_front();
            out.push_back(temp->val);
            if(temp->right != nullptr) tree.push_front(temp->right);
            if(temp->left != nullptr) tree.push_front(temp->left);
           
        }
        return out;
    }
};
