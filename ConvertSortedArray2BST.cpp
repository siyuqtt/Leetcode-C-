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
    private:
    TreeNode* buildTree( vector<int> &num){
        if (num.size() == 1){
            TreeNode * root = new TreeNode(num[0]);
            return root;
        }
        if (num.size() == 2){
            TreeNode * root = new TreeNode(num[0]);
            root->right = new TreeNode(num[1]);
            return root;
        }
        
            
            
            auto middle = num.begin() +num.size()/2;
            vector<int> leftnum(num.begin(), middle);
            vector<int> rightnum(middle+1, num.end());
            TreeNode* left = buildTree(leftnum);
            TreeNode* right = buildTree(rightnum);
            TreeNode * root = new TreeNode(*middle);
            root->left = left;
            root->right = right;
            return root;

    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if ( num.size() == 0) return nullptr;
         return buildTree(num);
    
    }
};
