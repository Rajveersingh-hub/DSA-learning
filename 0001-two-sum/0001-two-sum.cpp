class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
       vector<int>ans;
       unordered_map<int,int>mpp;
       for(int i=0;i<n;i++){
        int secondval=target-nums[i];
        if(mpp.find(secondval)!=mpp.end()){
            ans.push_back(i);
            ans.push_back(mpp[secondval]);
        }
        else{
            mpp[nums[i]]=i;
        }

       }
    
       return ans;
    }
};