class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //brute force tc-o(n2) sc-o(1)
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     int p=1;
        //     for(int j=i;j<nums.size();j++){
        //         p*=nums[j];
        //          ans=max(p,ans);
        //     }
           

        // }        
        int n=nums.size();
        int prefix=1;
        int sufix=1;
        int ans=nums[0];
        for(int i=0;i<n;i++){
            if(sufix==0){
                sufix=1;
            }
            if(prefix==0){
                prefix=1;
            }
          prefix*=nums[i];
          sufix*=nums[n-i-1];
          ans=max(ans,max(prefix,sufix));
        }
        return ans;
        
    }
};