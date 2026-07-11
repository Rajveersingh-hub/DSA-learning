class Solution {
public:
   vector<int> ncr(int row){
    vector<int>ans1;
    int ans=1;
    ans1.push_back(ans);
    for(int i=1;i<row;i++){
        ans=ans*(row-i);
        ans=ans/i;
        ans1.push_back(ans);
    }
    return ans1;
   }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=1;i<=numRows;i++){
            res.push_back(ncr(i));

        }
        return res;
    }
};