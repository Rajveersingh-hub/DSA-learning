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
    pair<bool,int>ctf(TreeNode* root){
        //base case
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
            pair<bool,int>p=make_pair(true,root->val);
            return p;
        }
        pair<bool,int>leftans=ctf(root->left);
        pair<bool,int>rightans=ctf(root->right);
        bool left=leftans.first;
        bool right=rightans.first;
        bool check=leftans.second+rightans.second==root->val;
        pair<bool,int>ans;
        if(left && right && check){
            ans.first=true;
            ans.second=2*root->val;
        }
        else{
            ans.first=false;

        }
        return ans;

    }
public:
    bool checkTree(TreeNode* root) {
        return ctf(root).first;
        
    }
};