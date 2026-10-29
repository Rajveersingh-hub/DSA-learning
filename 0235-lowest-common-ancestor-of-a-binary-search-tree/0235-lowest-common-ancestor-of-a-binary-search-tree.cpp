/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        // search in right
        if(root->val<p->val && root->val<q->val){
            TreeNode*right=lowestCommonAncestor(root->right,p,q);
            return right;

        }
        //search in left
        if(root->val>p->val && root->val>q->val){
            TreeNode*left=lowestCommonAncestor(root->left,p,q);
            return left;

        }
    
        return root;
        
    }
};