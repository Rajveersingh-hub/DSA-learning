class Solution {
    private:
    bool check(string &s,int skip){
        int i=0;
        int j=s.length()-1;
        while(i<j){
           if(i==skip){
            i++;
            continue;
           }
           if(j==skip){
            j--;
            continue;
           }
            else if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else if(s[i]!=s[j]){
                return check(s,j) || check(s,i);
            }
        }
        return true;
    }
};