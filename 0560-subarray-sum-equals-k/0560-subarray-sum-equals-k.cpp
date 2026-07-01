class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefixsum(nums.size(),0);
        int count=0;
        prefixsum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }unordered_map<int,int>m;
        for(int j=0;j<nums.size();j++){
            if(prefixsum[j]==k){
                count++;
            }
           int val=prefixsum[j]-k;
            if(m.find(val)!=m.end()){
                count+=m[val];   
            }
            if(m.find(prefixsum[j])==m.end()){
                m[prefixsum[j]]=0;
            }
            m[prefixsum[j]]++;

            
        }
                
                return count;
    }
     
};