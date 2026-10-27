/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    bool helper(TreeNode*root,long long min,long long max){
        if(root==NULL){
            return true;
        }
        else if(root->val>min && root->val<max){
            bool left=helper(root->left,min,root->val);
            bool right=helper(root->right,root->val,max);
            return left && right;
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,LLONG_MIN,LLONG_MAX);

        
    }
};