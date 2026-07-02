class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int ct0=0;
        // int ct1=0;
        // int ct2=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         ct0++;
        //     }
        //     else if(nums[i]==1){
        //         ct1++;
        //     }
        //     else{
        //         ct2++;
        //     }

        // }
        // for(int i=0;i<ct0;i++){
        //     nums[i]=0;
        // }
        // for(int i=ct0;i<ct0+ct1;i++){
        //     nums[i]=1;
        // }
        // for(int i=ct0+ct1;i<nums.size();i++){
        //     nums[i]=2;
        // }
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[high],nums[mid]);
                high--;
            }
        }

        
    }
};