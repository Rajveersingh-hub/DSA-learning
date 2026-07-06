class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int ccount=0;
       int lsmall=INT_MIN;
       int longest=0;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        if(nums[i]-1==lsmall){
            ccount++;
            lsmall=nums[i];

        }
        else if(nums[i]!=lsmall){
            ccount=1;
            lsmall=nums[i];
        }
        longest=max(longest,ccount);
       }
        return longest;
    }
};