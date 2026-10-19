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
    TreeNode* NodeToParent(TreeNode*root,int target, map<TreeNode*,TreeNode*>&ntp){
        TreeNode*res=NULL;
        queue<TreeNode*>q;
        q.push(root);
        if(root){
            ntp[root]=NULL;
        }
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(temp->val==target){
                res=temp;
            }
            if(temp->left){
                q.push(temp->left);
                ntp[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                ntp[temp->right]=temp;
            }
        }
        return res;

    }
    int burnTree(TreeNode*root, map<TreeNode*,TreeNode*>&ntp){
        map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(root);
        vis[root]=true;
        int ans=0;
        while(!q.empty()){
            bool flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                 TreeNode*temp=q.front();
                 q.pop();
                 if(temp->left && !vis[temp->left]){
                 flag=1;
                 q.push(temp->left);
                 vis[temp->left]=1;
                 }
                 if(temp->right && !vis[temp->right]){
                    flag=1;
                 q.push(temp->right);
                 vis[temp->right]=1;
                 }
                 if(ntp[temp] &&!vis[ntp[temp]]){
                    flag=1;
                    q.push(ntp[temp]);
                    vis[ntp[temp]]=1;
                 }
            }
            if(flag==1){
                ans++;
            }

        }
        return ans;


    }

public:
    int amountOfTime(TreeNode* root, int start) {
        // node to parent mapping-1
        // find start-2
        // burn the tree-3
       
        map<TreeNode*,TreeNode*>ntp;
        TreeNode*targetNode=NodeToParent(root,start,ntp);
       int ans= burnTree(targetNode,ntp);
        return ans;

        
    }
};