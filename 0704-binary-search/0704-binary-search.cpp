class Solution {
public:
    // int binary(vector<int>& nums, int target,int st,int end){
    //     if(st<=end){
    //     int mid=st+(end-st)/2;
        
    //     if(nums[mid]==target){
    //         return mid;
    //     }
    //     else if(nums[mid]<target){
    //         return binary(nums,target,mid+1,end);
    //     }
    //     else{
    //         return binary(nums,target,st,mid-1);
    //     }
    //     }
    //     return -1;
    // }
    int search(vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
       while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            st=mid+1;
        }

       }
        return -1;
    }
};