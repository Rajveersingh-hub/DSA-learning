class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=-1;
        if(haystack.length()<needle.length()){
            return ans;
        }
        for(int i=0;i<haystack.length();i++){
            ans=-1;
            bool found=true;
            for(int j=0;j<needle.length();j++){
                if(haystack[i+j]!=needle[j]){
                    found=false;
                   break;
                }
            }
            if(found){
                return i;
            }
           
        }
return ans;
        
    }
};