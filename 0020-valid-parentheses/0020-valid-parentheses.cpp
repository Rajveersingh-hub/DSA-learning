class Solution {
    private:
    bool matches(char temp,char ch){
        if((temp=='(' && ch==')') ||(temp=='{' && ch=='}') || (temp=='[' && ch==']')){
            return true;
        }
        return false;
    }
public:
    bool isValid(string s) {
        stack<char>ans;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                ans.push(ch);
            }
            else{
                if(!ans.empty()){
                    char temp=ans.top();
                    if(matches(temp,ch)){
                       ans.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            
        }
        if(ans.empty()){
            return true;
        }
        return false;

    }
};