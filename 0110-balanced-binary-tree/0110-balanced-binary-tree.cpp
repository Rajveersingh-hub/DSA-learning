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
    int height(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int lefth=height(root->left);
        int righth=height(root->right);
        int ans=max(lefth,righth)+1;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool leftb= isBalanced(root->left);
        bool rightb= isBalanced(root->right);
        bool diff= abs(height(root->left)-height(root->right))<=1;
        if(diff && leftb && rightb){
            return true;
        }
        return false;
    }
};