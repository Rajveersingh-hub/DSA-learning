class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxsum=INT_MIN;
       int sum=0;
       int st=0;
       int end=nums.size()-1;
       while(st<=end){
        sum+=nums[st];
        if(sum>maxsum){
            maxsum=sum;
        }
         if(sum<0){
            sum=0;

        }

    st++;
       }
       return maxsum;
    }
};
