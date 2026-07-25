class Solution {
public:
 
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
       int st=0;
       int end=n-1;
       int first=-1;
       while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==target){
            first=mid;
            end=mid-1;
        }
        else if(nums[mid]<target){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
       }
       ans.push_back(first);
        int low=0;
        int last=-1;
       int high=n-1;;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            last=mid;
            low=mid+1;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
       ans.push_back(last);
       

       
        
        return ans;
    }
};