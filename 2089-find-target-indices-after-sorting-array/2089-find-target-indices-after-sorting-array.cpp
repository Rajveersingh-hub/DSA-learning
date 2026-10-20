class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
        int first=-1;
        int last=-1;
        int st = 0;
        int end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                first=mid;
                end=mid-1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                st=mid+1;
            }
        }
        st=0;
        end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                last=mid;
                st=mid+1;

            }
              else if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                st=mid+1;
            }
        }
        
        for(int i=first;i<=last;i++){
            if(first==-1 || last==-1){
                return ans;
            }
            ans.push_back(i);
        }
        return ans;
    }
};