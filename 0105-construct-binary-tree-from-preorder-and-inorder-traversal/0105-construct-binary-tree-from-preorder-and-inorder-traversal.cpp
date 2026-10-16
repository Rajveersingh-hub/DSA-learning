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
    int find(vector<int>& inorder,int el){
        int n=inorder.size();
        for(int i=0;i<n;i++){
            if(inorder[i]==el){
                return i;
            }
        }
        return -1;
    }
    TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int &preidx,int inorderst,int inorderend,int n){
        // base case
        if(preidx>n || inorderst>inorderend){
            return NULL;
        }
        int el=preorder[preidx++];
        int pos=find(inorder,el);
        TreeNode*root=new TreeNode(el);
        // recursive calls
        root->left=solve(preorder,inorder,preidx,inorderst,pos-1,n);
        root->right=solve(preorder,inorder,preidx,pos+1,inorderend,n);
        return root;

    }
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int n=preorder.size();
        int preidx=0;
        TreeNode *ans=solve(preorder,inorder,preidx,0,n-1,n);
        return ans;


    }

};