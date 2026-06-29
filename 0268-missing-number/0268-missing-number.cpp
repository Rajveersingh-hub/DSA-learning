class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int range=nums.size();
        int assumed_sum=0;
        int actual_sum=0;
        for(int i=0;i<=range;i++){
            assumed_sum+=i;
        }
        for(int i=0;i<range;i++){
            actual_sum+=nums[i];
        }
        int missing_number=assumed_sum-actual_sum;
        return missing_number;
        
    }
};