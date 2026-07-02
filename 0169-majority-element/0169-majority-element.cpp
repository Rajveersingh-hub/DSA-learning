class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int frq=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(frq==0){
                frq=1;
                ans=nums[i];
            }
            else if(ans==nums[i]){
                frq++;
            }
            else{
            frq--;}
        }
        return ans;
        // unordered_map<int,int>mpp;
        // for(int i=0;i<nums.size();i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it:mpp){
        //     if(it.second>(nums.size())/2){
        //         return it.first;
        //     }
        // }
        // return -1;
    }
};