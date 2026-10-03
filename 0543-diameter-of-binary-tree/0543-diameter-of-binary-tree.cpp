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
public:
  pair<int,int>diameterfast(TreeNode* root){
     if(root==NULL){
         pair<int,int>p=make_pair(0,0);
        return p;
     }
     pair<int,int>leftd=diameterfast(root->left);
     pair<int,int>rightd=diameterfast(root->right);
     int op1=leftd.first;
     int op2=rightd.first;
     int op3=leftd.second+rightd.second+1;
     pair<int,int>ans;
     ans.first=max(op1,max(op2,op3));
     ans.second=max(leftd.second,rightd.second)+1;
     return ans;


  }
    int diameterOfBinaryTree(TreeNode* root) {
         return diameterfast(root).first-1;
        
    }
};