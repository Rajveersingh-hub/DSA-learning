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
    void solve(TreeNode* root,vector<int>&path,int &cnt,int targetSum){
        if(root==NULL){
            return;
        }
        // store the data of present node in array
        path.push_back(root->val);
        // left call
        solve(root->left,path,cnt,targetSum);
        //right call
        solve(root->right,path,cnt,targetSum);
        int size=path.size();
        long long sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==targetSum){
            cnt++;
            }
        }
        path.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int cnt=0;
        solve(root,path,cnt,targetSum);
        return cnt;
        
    }
};