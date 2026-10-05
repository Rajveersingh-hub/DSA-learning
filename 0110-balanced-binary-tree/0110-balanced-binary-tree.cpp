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
//     private:
//     int height(TreeNode*root){
//         if(root==NULL){
//             return 0;
//         }
//         int lefth=height(root->left);
//         int righth=height(root->right);
//         int ans=max(lefth,righth)+1;
//         return ans;
//     }
// public:
//     bool isBalanced(TreeNode* root) {
//         if(root==NULL){
//             return true;
//         }
//         bool leftb= isBalanced(root->left);
//         bool rightb= isBalanced(root->right);
//         bool diff= abs(height(root->left)-height(root->right))<=1;
//         if(diff && leftb && rightb){
//             return true;
//         }
//         return false;
//     }
// };
// new method TC-O(N) SC-O(N) using PAIRS
public:
    pair<bool,int> isf(TreeNode* root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        pair<bool,int>lefta=isf(root->left);
        pair<bool,int>righta=isf(root->right);
        bool leftans=lefta.first;
        bool rightans=righta.first;
        bool diff=abs(lefta.second-righta.second)<=1;
        pair<bool,int>ans;
        ans.second=max(lefta.second,righta.second)+1;
        if(leftans &&rightans && diff){
            ans.first=1;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {

       return isf(root).first;

    }
};
