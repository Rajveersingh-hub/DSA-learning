class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        //BRUTE FORCE 
        vector<int>ans;
    //     vector<int>vis(m,0);
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(nums1[i]==nums2[j] && vis[j]==0){
    //                 if(ans.empty() || ans.back()!=nums1[i]){
    //                 ans.push_back(nums1[i]);
    //                 vis[j]=1;
    //                 break;
    //                 }
    //             }
    //             if(nums2[j]>nums1[i]){
    //                 break;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    //TWO POINTERS
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            i++;
        }
        else if(nums1[i]>nums2[j]){
            j++;

        }
        else{
            if(ans.empty() || ans.back()!=nums1[i]){
                ans.push_back(nums1[i]);
               
        }
         i++;
         j++;
            }

    }
        return ans;
    }
};