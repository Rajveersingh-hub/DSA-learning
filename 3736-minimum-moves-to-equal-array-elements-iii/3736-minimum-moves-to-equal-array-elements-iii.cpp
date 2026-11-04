class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=INT_MIN;
        // find max element in array
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=maxi){
                ans+=maxi-nums[i];
            }
        }

        return ans;
    }
};