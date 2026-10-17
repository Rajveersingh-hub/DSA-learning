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
   void find(vector<int>& inorder,unordered_map<int,int>&idx){
        int n=inorder.size();
        for(int i=0;i<n;i++){
           idx[inorder[i]]=i;
        }
    }
    TreeNode*solve(unordered_map<int,int>&idx,vector<int>& preorder, vector<int>& inorder,int &preidx,int inorderst,int inorderend,int n){
        // base case
        if(preidx>n || inorderst>inorderend){
            return NULL;
        }
        int el=preorder[preidx++];
        int pos=idx[el];
        TreeNode*root=new TreeNode(el);
        // recursive calls
        root->left=solve(idx,preorder,inorder,preidx,inorderst,pos-1,n);
        root->right=solve(idx,preorder,inorder,preidx,pos+1,inorderend,n);
        return root;

    }
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        unordered_map<int,int>idx;
        int n=preorder.size();
        int preidx=0;
        find(inorder,idx);
        TreeNode *ans=solve(idx,preorder,inorder,preidx,0,n-1,n);
        return ans;


    }

 */
class Solution {
    private:
     void find(vector<int>& inorder,unordered_map<int,int>&idx){
        int n=inorder.size();
        for(int i=0;i<n;i++){
           idx[inorder[i]]=i;
        }
    }
    TreeNode*solve(unordered_map<int,int>&idx,vector<int>& postorder, vector<int>& inorder,int &postidx,int inorderst,int inorderend,int n){
        // base case
        if(postidx<0|| inorderst>inorderend){
            return NULL;
        }
        int el=postorder[postidx--];
        int pos=idx[el];
        TreeNode*root=new TreeNode(el);
        // recursive calls
        root->right=solve(idx,postorder,inorder,postidx,pos+1,inorderend,n);
          root->left=solve(idx,postorder,inorder,postidx,inorderst,pos-1,n);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          unordered_map<int,int>idx;
        int n=postorder.size();
        int postidx=n-1;
        find(inorder,idx);
        TreeNode *ans=solve(idx,postorder,inorder,postidx,0,n-1,n);
        return ans;


        
    }
};