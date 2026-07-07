class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    //    int ccount=0;
    //    int lsmall=INT_MIN;
    //    int longest=0;
    //    sort(nums.begin(),nums.end());
    //    for(int i=0;i<nums.size();i++){
    //     if(nums[i]-1==lsmall){
    //         ccount++;
    //         lsmall=nums[i];

    //     }
    //     else if(nums[i]!=lsmall){
    //         ccount=1;
    //         lsmall=nums[i];
    //     }
    //     longest=max(longest,ccount);
    //    }
    //     return longest;
    int count=0;
    int longest=0;
    unordered_set<int>s;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
    }
    for(auto el:s){
        if(s.find(el-1)==s.end()){
            count=1;
            int x=el;
            while(s.find(x+1)!=s.end()){
                count++;
                x+=1;
            }
            longest=max(longest,count);
        }
    }
    return longest;
    }
};